#include<bits/stdc++.h>
using namespace std;
#define uLL unsigned long long
int n,q,m,ans;
string a,b;
map<uLL,map<uLL,int>>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		uLL ha=0,hb=0;
		for(char i:a)ha=ha*131+i;
		for(char i:b)hb=hb*131+i;
		mp[ha][hb]++;
	}
	if(n>1e4&&q>1e4){
		while(q--)cout<<"0\n";
		return 0;
	}
	while(q--){
		cin>>a>>b;
		m=a.length(),ans=0;
		if(m!=b.length()){
			cout<<"0\n";
			continue;
		}
		int r=m-1;
		while(a[r]==b[r])r--;
		for(int i=0;i<m;i++){
			uLL ha=0,hb=0;
			for(int j=i;j<m;j++){
				ha=ha*131+a[j],hb=hb*131+b[j];
				if(j>=r)ans+=mp[ha][hb];
			}
			if(a[i]!=b[i])break;
		}
		cout<<ans<<'\n';
	}
}
