#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL n,q;
string s[200005][2];
string x,y;
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
	}
	while(q--){
		cin>>x>>y;x='!'+x,y='!'+y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			continue;
		}
		LL res=0;
		for(int i=1;i<=n;i++){
			vector<LL> st,stt;
			LL len=s[i][0].size()-1;
			for(int l=1;l+len-1<x.size();l++){
				bool flag=1;
				for(int j=l;j<=l+len-1;j++){
					if(s[i][0][j-l+1]!=x[j]){
						flag=0;
						break;
					}
				}
				if(flag) st.push_back(l);
			}
			len=s[i][1].size()-1;
			for(int l=1;l+len-1<y.size();l++){
				bool flag=1;
				for(int j=l;j<=l+len-1;j++){
					if(s[i][1][j-l+1]!=y[j]){
						flag=0;
						break;
					}
				}
				if(flag) stt.push_back(l);
			}
//			cout<<i<<"\n";
//			for(auto j : st) cout<<j<<' ';
//			cout<<"\n";
//			for(auto j : st) cout<<j<<' ';
//			cout<<"\n-------\n";
			for(int i=0,j=0;i<st.size()&&j<stt.size();){
				if(st[i]==stt[j]){
					bool flag=1;
					for(int p=1;p<st[i];p++){
						if(x[p]!=y[p]){
							flag=0;
							break;
						}
					}
					for(int p=st[i]+len;p<x.size();p++){
						if(x[p]!=y[p]){
							flag=0;
							break;
						}
					}
					if(flag) res++;
					//else cout<<st[i]<<endl;
					i++,j++;
				}
				else if(st[i]<stt[j]) i++;
				else j++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
