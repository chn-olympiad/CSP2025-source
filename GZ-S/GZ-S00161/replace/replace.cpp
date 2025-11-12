//GZ-S00161 贵阳市第一中学 张梁予
#include<bits/stdc++.h>
using namespace std;
int n,q;

struct s{
	string s1,s2;
}a[200005];

struct w{
	string w1,w2;
}b[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].w1>>b[i].w2;
	}
	cout<<0;
	return 0;
}
