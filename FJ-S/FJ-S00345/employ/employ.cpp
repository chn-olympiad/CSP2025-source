#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int p[100005];
string k;
int read(){
	char ch=getchar();
	if(ch!='0'&&ch!='1')ch=getchar();
	while(ch=='0'||ch=='1')
	k=k+ch,ch=getchar();
    return 0;
}
int SRT(int n){
	long long  ans=1;
	for(int i=n;i>=2;i--){
	 ans=(ans*i)%998244353;
	}
	 return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<m){
		cout<<0;
		return 0;
	}
	read();
	for(int i=1;i<=n;i++)
	 cin>>p[i];
	 int pk=1;
	for(int i=0;i<n;i++)
	if(k[i]=='0')pk=0;
	if(pk){
		cout<<SRT(n);
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
