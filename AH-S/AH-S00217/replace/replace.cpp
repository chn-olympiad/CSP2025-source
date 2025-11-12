#include <bits/stdc++.h>
using namespace std;
struct node{
	string s1,s2;
	long long len,findb;
}x[200005];
long long n,q;
string s5;
int main(){
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	scanf ("%lld%lld",&n,&q);
	for (int i=1;i<=n;i++){
		cin>>x[i].s1>>x[i].s2;
		x[i].len=x[i].s1.size();
		x[i].findb=(long long)(x[i].s1.find('b')-x[i].s2.find('b'));
	}
	for (int i=1;i<=q;i++){
		string s3=s5,s4=s5;
		cin>>s3>>s4;
		long long ans=0,fb;
		fb=(long long)(s3.find('b')-s4.find('b'));
		for (int j=1;j<=n;j++){
			if (!(fb-x[j].findb))
				ans++;
		}
		printf ("%lld\n",ans);
	}
	return 0;
}
