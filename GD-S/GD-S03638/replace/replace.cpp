#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL n,q;
struct zu{
	string s1,s2;
}a[N];
struct question{
	string t1,t2;
}b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i].s1>>a[i].s2;
	for(int i=1;i<=q;i++) cin>>b[i].t1>>b[i].t2;
	return 0;
}

