#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[505];
bool s[505],b[505];
void q(int k,int t){
	if(k>=n){
		if(n-t>=m) ans=(ans+1)%998244353;
		return;
	}
	if(n-t<m) return;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(t>=a[i]){
				q(k+1,t+1);
			}
			else if(s[k+1]==1){
				q(k+1,t);
			}
			else{
				q(k+1,t+1);
			}
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		char ch;
		scanf("%c",&ch);
		if(ch=='1') s[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	q(0,0);
	cout<<ans;
	return 0;
}
