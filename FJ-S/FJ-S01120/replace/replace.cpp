#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,q;
string a1[N],a2[N],b1[N],b2[N];
int ans[N],m[N],c[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a1[i]>>a2[i];
	for(int i=1;i<=q;i++) cin>>b1[i]>>b2[i];
	for(int i=1;i<=q;i++){
		int l=0,r=0;
		for(int j=0;j<b1[i].size();j++)
			if(b1[i][j]=='b') {
				l=j;
				break;
			}
		for(int j=0;j<b2[i].size();j++)
			if(b2[i][j]=='b') {
				r=j;
				break;
			}
		m[i]=r-l;
		c[i]=l;
	}
	for(int i=1;i<=n;i++){
		int l=0,r=0;
		for(int j=0;j<a1[i].size();j++)
			if(a1[i][j]=='b') {
				l=j;
				break;
			}
		for(int j=0;j<a2[i].size();j++)
			if(a2[i][j]=='b') {
				r=j;
				break;
			}
		for(int j=1;j<=q;j++)
			if((r-l)==m[j]&&l<=c[j])
				ans[j]++;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
} 
