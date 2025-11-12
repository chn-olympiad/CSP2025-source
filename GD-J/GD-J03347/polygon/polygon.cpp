#include<bits/stdc++.h>
using namespace std;
int n[5005];
int dp[1000][1000];
int dp2[1000][1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int ans=0;
	int count=0;	
	for(int i=1;i<=a;i++){
		cin>>n[i];
		if(n[i]==1){
			count+=1;
		}
	}
	sort(n+1,n+1+a);
	if(a==3){
		if(n[1]+n[2]+n[3]>n[3]*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(a<3){
		cout<<0;
	}
	else if(count==a){
		int sum=0;
		int s=1;
		int p=1;
		for(int i=3;i<=a;i++){
			for(int j=1;j<=i;j++){
				s*=j;
				p*=a-(j-1);
			}
			sum+=p/s;
		}
		cout<<sum;
	}
}
