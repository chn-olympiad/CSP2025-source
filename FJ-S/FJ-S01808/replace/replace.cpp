#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200005],s2[200005];
struct wt{
	string t1,t2;
	int op;
}qs[200005];
int main(){
		freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		printf("0\n");
	}
	return 0;
}