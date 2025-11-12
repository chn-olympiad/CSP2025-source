#include<bits/stdc++.h>
using namespace std;
int n,m,s[505],c[11111],r;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<=n;i++){
		if(c[i]>s[i]){
			r++;
		}
		if(r==m){
			break;
		}
	}
	cout<<m;
}
