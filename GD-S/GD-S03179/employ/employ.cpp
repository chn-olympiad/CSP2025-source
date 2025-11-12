#include<bits/stdc++.h>
using namespace std;
#define int long long
void file(string fi){
	freopen((fi+".in").data(),"r",stdin);
	freopen((fi+".out").data(),"w",stdout);
} 
int n,m,c[100010],a[100010],sm[100010];
string s;
signed main(){
	file("employ");
	cin>>n>>m>>s;
	for(int i=0;i<n;++i)cin>>c[i];
	for(int i=0;i<n;++i)a[i]=i;
	int ans=0;
	do{
		int r=0,g=0;
		for(int i=0;i<n;++i)
			if(g>=c[a[i]]||s[i]=='0')
				++g;
			else ++r;
		if(r>=m)++ans;
	}while(next_permutation(a,a+n));
	cout<<ans;
	return 0;
}
