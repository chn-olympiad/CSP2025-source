#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
map<string,string>mp;
string to;
void dfs(string a,int st,int ed){
    if(a==to){
        ans++;
        return ;
    }
    for(int i=0;i<st;i++){
        for(int j=i+1;j<st;j++){
            string c,d,e;
            for(int k=0;k<i;k++){
                c+=a[k];
            }
            for(int k=i;k<=j;k++){
                d+=a[k];
            }
            for(int k=j+1;k<(int)a.size();k++){
                e+=a[k];
            }
            if(mp[d].size()!=0){
                string g=mp[d];
                mp[d]="";
                dfs(c+g+e,i,j);
                mp[d]=g;
            }
        }
    }
    for(int i=ed+1;i<(int)a.size();i++){
        for(int j=i+1;j<(int)a.size();j++){
            string c,d,e;
            for(int k=0;k<i;k++){
                c+=a[k];
            }
            for(int k=i;k<=j;k++){
                d+=a[k];
            }
            for(int k=j+1;k<(int)a.size();k++){
                e+=a[k];
            }
            if(mp[d].size()!=0){
                string g=mp[d];
                mp[d]="";
                dfs(c+g+e,i,j);
                mp[d]=g;
            }
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    while(q--){
        string a;
        cin>>a>>to;
//        for(auto u:mp){
//        	for(int i=0;i<(int)(a.size()-u.first.size()+1);i++){
//        		string c,d,e;
//                for(int k=0;k<i;k++){
//                    c+=a[k];
//                }
//                for(int k=i;k<=i+(int)u.first.size()-1;k++){
//                    d+=a[k];
//                }
//                for(int k=i+(int)u.first.size();k<(int)a.size();k++){
//                    e+=a[k];
//                }
//                if(d==u.first){
//                	string g=u.first;
//                	u.first="";
//                    dfs(c+g+e,i,(int)u.first.size()-1);
//                    u.first=g;
//                }
//			}
//		}
        for(int i=0;i<(int)a.size();i++){
            for(int j=i+1;j<(int)a.size();j++){
                string c,d,e;
                for(int k=0;k<i;k++){
                    c+=a[k];
                }
                for(int k=i;k<=j;k++){
                    d+=a[k];
                }
                for(int k=j+1;k<(int)a.size();k++){
                    e+=a[k];
                }
                if(mp[d].size()!=0){
                	string g=mp[d];
                	mp[d]="";
                    dfs(c+g+e,i,j);
                    mp[d]=g;
                }
            }
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/