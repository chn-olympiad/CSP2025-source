#include<bits/extc++.h>
using namespace std;
#define AK ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqrt sqrtl
#define int long long
using namespace __gnu_cxx;
map<crope,crope> mp;
map<crope,bool> ex;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//不好是KMP，我们没救了！
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		crope s1,s2;
		string ss1,ss2;
		cin>>ss1>>ss2;
		for(int i=0;i<ss1.size();i++)s1.push_back(ss1[i]);
		for(int i=0;i<ss2.size();i++)s2.push_back(ss2[i]);
		mp[s1]=s2;
		ex[s1]=1;
	}
	while(q--){
		crope s1,s2;
		string ss1,ss2;
		cin>>ss1>>ss2;
		crope dif;
		for(int i=0;i<ss1.size();i++){
			if(ss1[i]!=ss2[i])dif.push_back(ss1[i]);
		}
		for(int i=0;i<ss1.size();i++)s1.push_back(ss1[i]);
		for(int i=0;i<ss2.size();i++)s2.push_back(ss2[i]);
		int ans=0;
		for(int l=0;l<ss1.size();l++){
			for(int r=l;r<ss1.size();r++){
				if((ex[s1.substr(l,r)]&&mp[s1.substr(l,r)]==s2.substr(l,r)&&s1.substr(0,l-1)==s2.substr(0,l-1)&&s1.substr(r+1,ss1.size()-1)==s2.substr(r+1,ss2.size()-1))||(ex[s1]&&mp[s1]==s2&&l==0&&r==ss1.size()-1)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/