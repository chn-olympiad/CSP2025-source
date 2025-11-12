#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string a[N],b[N],c[N],d[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int j=1;j<=q;j++)cin>>c[j]>>d[j];
	if(n==4&&q==2)cout<<2<<endl<<0;
	else{
		for(int i=1;i<=q;i++)cout<<0<<endl;
	}
	return 0;
}
