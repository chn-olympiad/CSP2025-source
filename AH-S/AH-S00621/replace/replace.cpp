#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,q;
string s[200000+5][4],t[200000+5][4];
int lent;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
    for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2],lent+=t[i][1].size()+t[i][2].size();
    if(lent<=2000){
        for(int k=1;k<=q;k++){
            int l,r;
            int ret=0;
            for(l=0;t[k][1][l]==t[k][2][l]&&l<t[k][1].size();l++);
            for(r=t[k][1].size()-1;t[k][1][r]==t[k][2][r]&&r>=0;r--);
            for(int i=1;i<=n;i++){
                int pos1=t[k][1].find(s[i][1]),pos2=t[k][2].find(s[i][2]);
                for(;(pos1!=string::npos&&pos2!=string::npos);){
                    if(pos1==pos2&&pos1<=l&&r<=pos1+s[i][1].size()-1) ret++;
                    while(pos1<pos2) pos1=t[k][1].find(s[i][1],pos1+1);
                    pos2=t[k][2].find(s[i][2],pos2+1);
                }
            }cout<<ret<<endl;
        }
        return 0;
    }
    
    
    map<int,vector<pair<int,int> > > mp;
    for(int i=1;i<=n;i++){
		int k=s[i][1].find('b')-s[i][2].find('b');
		mp[k].push_back(make_pair(s[i][1].size()-1-s[i][1].find('b'),s[i][2].find('b')));
	}
	for(auto it=mp.begin();it!=mp.end();it++) sort(it->second.begin(),it->second.end());
	for(int i=1;i<=q;i++){
		int k=t[i][1].find('b')-t[i][2].find('b');
		int pos1=t[i][1].size()-1-t[i][1].find('b'),pos2=t[i][2].find('b');
		int ret=0;
		for(pair<int,int> it:mp[k]){
			if(pos1>=it.second&&pos2>=it.second){
				ret++;
			}
		}cout<<ret<<endl;
	}
    return 0;
}
