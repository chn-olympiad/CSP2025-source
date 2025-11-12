#include<bits/stdc++.h>
using namespace std;
long long int note[5001];
const long long int N=998244353;
int main(){
	note[0]=1;
	note[1]=1;
	int n,ans=0;
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int mx=max(a,max(c,b));
		if(a+b+c>2*mx) cout<<1;
		else cout<<0;
		return 0;
	}
	else{
		for(int i=2;i<=n;i++){
			note[i]=(note[i-1]*i)%N;
		}
		int a=note[n];
		int b,c;
		for(int i=3;i<=n;i++){
			b=note[i];c=note[n-i];
			int temp=a/b/c;
			ans+=temp;
		}
	}
	cout<<ans;
}