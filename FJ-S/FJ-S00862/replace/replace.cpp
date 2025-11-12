#include<bits/stdc++.h>
using namespace std;
long long n,q;
string sa[200010],sb[200010],ta[200010],tb[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++) cin>>sa[i]>>sb[i];
	for(int j = 1;j <= q;j++) cin>>ta[j]>>tb[j];
	for(int j = 1;j <= q;j++){
		long long x=0;
		for(int i = 1;i <= n;i++){
			if(ta[j]==sa[i] && tb[j]==sb[i]) x+=2;
		} 
		cout<<x<<endl;
	}
	return 0;
}
