# include <bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s[200008][3];
string t1,t2,ls1,ls2,ls3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		ans=0;
		for(int i=1;i<=n;i++){
			int pl=int(t1.find(s[i][1]));
			while(pl!=-1){
				ls1=t1;
				ls2=s[i][1];
				ls1.erase(pl,ls2.length());
				ls3=s[i][2];
				ls1.insert(pl,ls3);
				if(ls1==t2){
					ans++;
				}
				pl=int(t1.find(s[i][1],pl+1));
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}