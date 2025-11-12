#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int score[n*m]={},R=0;
	for(long long i=0;i<n*m;i++){
		cin>>score[i];
	}
	R=score[0];
	sort(score,score+n*m,cmp);
	int Rindex=0;
	for(long long i=0;i<n*m;i++){
		if(score[i]==R){
			Rindex=i+1;
			cout<<Rindex<<" ";
			break;
		}
	}
	cout<<int(Rindex/n)<<" ";
	if(int(Rindex/n)%2==0){
		cout<<n-Rindex%n;
	}
	else{
		cout<<1+Rindex%n;
	}
	return 0;
}
