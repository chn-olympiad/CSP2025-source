#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,k;
bool flag1,flag2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag1=true;
        if(a[i]>1) flag2=true;
	}
	if(flag1==false&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(flag2==false&&k==0){
		long long cnt=0;
		bool f[N];
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			if(a[i]==1&&a[i+1]==1&&f[i]==0&&f[i+1]==0)
			    cnt++,f[i]=f[i+1]=1;
		}
		cout<<cnt;
		return 0; 
	}
	else if(flag2==false&&k==1){
		long long cnt=0;
		for(int i=1;i<=n;i++)
		    if(a[i]==1) cnt++;
		cout<<cnt;
		return 0;
	}
    return 0;
}
