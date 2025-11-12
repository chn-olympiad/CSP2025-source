#include<bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010],tmp;
string s,goal;
long long n,q,ans,l,r;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}for(int i=1;i<=q;i++){
		cin>>s>>goal;
		ans=0;
		for(int j=1;j<=n;j++){
			l=s.find(s1[j]);
			r=l+s1[j].size();
			if(l>=0&&l<(long long)s.size()&&r>=0&&r<(long long)s.size()){
				tmp=s.substr(0,l)+s2[j]+s.substr(r,s.size());
				if(tmp==goal) ans++;
			}
		}cout<<ans<<endl;
	}
	return 0;
}
