#include<bits/stdc++.h>
using namespace std;
int n,m,s,b[1000],c[1000];
string a;
long long re;
void f(int k,int s){
	if(k==n){
		if(n-s>=m)re++;
		return;
	}
	for(int i=0;i<n;i++)if(!c[i]){
		c[i]=1;
		if(s>=b[i]||a[i]-'0'==0){
			f(k+1,s+1);
		}
		else f(k+1,s);
		c[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=0;i<n;i++){
		cin>>b[i];
//		if(b[i]!=0)s++,cout<<s<<endl;
	}
	f(0,0);
//	for(int i=s;i<=n;i++)re=re*i%998244353;
	cout<<re%998244353;
}
