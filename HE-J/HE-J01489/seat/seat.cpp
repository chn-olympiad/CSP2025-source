#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
long long score[maxn];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long temp=0;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
		temp=score[1];
	}
	sort(score,score+n*m,cmp);
	long long pos=0;
	for(int i=1;i<=n*m;i++){
		if(score[i]==temp){
			pos=i+1;
			break;
		}
	}
	//cout<<pos<<endl;
	long long first=(pos-1)/n+1;
	long long second=0;
	if(first%2==1){
		if(pos%n==0) second=n; 
		else second=pos%n;
	}
	else if(first%2==0){
		if(pos%n==0) second=1;
		else second=n-pos%n+1;
	}
	cout<<first<<" "<<second;
	
	
	
	
	
	return 0;
}
