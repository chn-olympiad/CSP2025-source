#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int a[5005],n;
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	    if(a[i]>1) flag=true;
	}
	if(flag==false){
		long long sum=0;
		for(int i=3;i<n;i++){
			int f1=i,f2=n-i;
			if(f1>f2) swap(f1,f2);
			long long ans=1,cnt=1;
			for(int j=n;j>f1;j--)
			    ans=(ans*j)%Mod;
			for(int j=2;j<=f2;j++)
			    cnt=(cnt*j)%Mod;
			sum=(sum+(ans/cnt))%Mod;
		}
		cout<<sum+1;
	}
	else if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]+a[3]>2*a[3])
		    cout<<1;
		else cout<<0;
		return 0;
	}
	
	return 0;
}
