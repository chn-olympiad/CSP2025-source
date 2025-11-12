#include<bits/stdc++.h>
using namespace std;
int score[400];
int a1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>score[i];
	}
	sort(score+2,score+n*m+1,cmp);
	//看看能排第几
	int th=0;
	for(int i=2;i<=n*m;i++){
		th++;
		if(score[i]<a1)break;
	} 
	if((th/n)%2==0){
		if(th%n==0)cout<<th/n<<" "<<th%n+1;
		else cout<<th/n+1<<" "<<th%n;
	}
	else{
		if(th%n==0)cout<<th/n<<" "<<n-th%n;
		else cout<<th/n+1<<" "<<n-th%n+1;
	}
	
	return 0;
}
