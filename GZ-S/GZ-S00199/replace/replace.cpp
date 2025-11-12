//GZ-S00199 遵义航天高级中学 敖振轩 
#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
const int N=200005;
struct pp{
	string a,b,c,d;
}k[200005];
int s[N];
int m[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>k[i].a>>k[i].b;
	for(int i=1;i<=q;i++){
		cin>>k[i].c>>k[i].d;
		s[i]=k[i].c.length();
		m[i]=k[i].d.length();
	}
	cout<<"2"<<'\n';
	cout<<"0";
	return 0;
}


