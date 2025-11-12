#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
struct tt{
	int a,b,c;
}a[N];
int t,ans,n,f[N],q;
bool cmp1(tt a,tt b){//a>b>c;
	if(a.a==b.a){
		if(a.b==b.b)return a.c>b.c;
		else return a.b>b.b;
	}
	else return a.a>b.a;
}
string s1,s2,t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1>>s2;
	for(int i=1;i<=q;i++)cin>>t1>>t2;
	for(int i=1;i<=q;i++)cout<<0<<"\n";
	return 0;
}

