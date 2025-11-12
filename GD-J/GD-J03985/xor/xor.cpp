#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int s[N];
int f[N];
int n,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int x;
	cin>>x;
	s[1]=x;
	for(int i=2;i<=n;i++){
		cin>>x;
		s[i]=(s[i-1]^x);
	}
	if(m==0){
		if(s[1]==m) f[1]=1;
		for(int i=2;i<=n;i++){
			for(int k=0;k<i;k++){
				int sum=(s[k]^s[i]); 
				int ans=0;
				if(sum==m) ans++;
				f[i]=max(f[i],f[k]+ans);
//				cout<<f[i]<<" ";
			}
		}	
	}
//	for(int i=1;i<=n;i++) cout<<s[i]<<" ";
	else{
		if(s[1]==m) f[1]=1;
		for(int i=2;i<=n;i++){
			for(int k=0;k<=i;k++){
				int sum=(s[k]^s[i]); 
				int ans=0;
				if(sum==m) ans++;
				f[i]=max(f[i],f[k]+ans);
//				cout<<f[4]<<" ";
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<f[n];
	return 0;
} 
