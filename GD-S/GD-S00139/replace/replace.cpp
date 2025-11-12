#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,bool> mp;
int n,q;
string a,b,ta,tb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		mp[make_pair(a,b)]=1;
	}
	while(q--){
		int ans=0;
		cin>>ta>>tb;
		int l=-1,r=-1;
		int m=ta.size();
		ta=" "+ta+" ",tb=" "+tb+" ";
		for(int i=1;i<=m;i++){
			if(ta[i]!=tb[i] && l==-1){
				l=i;
				break;
			}
		}
		for(int i=m;i>=l;i--){
			if(ta[i]!=tb[i]){
				r=i;
				break;
			}
		}
		string t,ch;
		for(int i=l;i<=r;i++) t+=ta[i],ch+=tb[i];
		for(;l>=1;l--){
			string tt=t,tch=ch;
			for(int tr=r;tr<=m;tr++){
//				cout<<tt<<' '<<tch<<endl;
				if(mp[make_pair(tt,tch)]) ans++;//,cout<<tt<<' '<<tch<<"OK"<<endl;
				
				tt+=ta[tr+1];
				tch+=tb[tr+1];
			}
			t=ta[l-1]+t;
			ch=tb[l-1]+ch;
		}
		cout<<ans<<endl;
	}
	return 0;
}
