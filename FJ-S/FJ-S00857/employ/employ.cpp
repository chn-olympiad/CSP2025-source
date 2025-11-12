#include<bits/stdc++.h>
using namespace std;
int n,m,b[501],q,qq,qqq;
long long num=1;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]==0)q=1; 
		if(a[i]==1)qq=1;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i]; 
		if(b[i]==0)q=1;
		if(b[i]!=0)qqq=1;
	}
	if(n==m){
		if(q==1)cout<<0;
		else cout<<1;
		return 0;
	}
	if(m==1){
		if(qq==1&&qqq==1){
			for(int i=1;i<=n;i++){
				num=(num*i)%998244353;
			}
			cout<<num;
			return 0;
		}
		cout<<0;
		return 0;
	} 
	return 0;
}
