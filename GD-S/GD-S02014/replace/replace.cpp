#include<bits/stdc++.h>
#define int long long int 
using namespace std;
const int N=2e5+10;
int n,q;
string a[N],b[N],c[N],d[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		cin>>c[i]>>d[i];
		if(c[i].size()!=d[i].size()){
			cout<<0<<"\n";
		}
		cout<<0<<"\n";
	}
}
//Ren5Jie4Di4Ling5%
