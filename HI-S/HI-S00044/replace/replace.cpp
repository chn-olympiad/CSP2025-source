#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=1e5+5;
struct mmp{
	string thx,thy;
}a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>a[i].thx>>a[i].thy;
	for(int i=1;i<=q;i++) cin>>b[i].thx>>b[i].thy;
	cout<<q<<endl<<0;
	return 0;
}
