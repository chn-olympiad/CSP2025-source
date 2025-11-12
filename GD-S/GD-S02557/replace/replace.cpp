#include<bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<=m;++i)
#define ref(i,n,m) for(int i=n;i>=m;--i)
#define ll long long
using namespace std;
const int N=1e2+5;
int n,T;
string s1[N],s2[N];
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>T;
	rep(i,1,n) cin>>s1[i]>>s2[i];
	while(T--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int start=0,end=(int)(t1.size())-1;
		rep(i,start,end){
			if(t1[i]!=t2[i]){
				start=i;
				break;
			}
		}
		ref(i,end,start){
			if(t1[i]!=t2[i]){
				end=i;
				break;
			}
		}
		int res=0;
		rep(i,1,n){
//			cout<<i<<" "<<(s1[i].size())<<" "<<(end-start+1)<<"\n"; 
			if(s1[i].size()<end-start+1) continue;
			bool flag=0;
			cout<<end-(int)(s1[i].size())+1<<"\n";
			rep(j,max(0,end-(int)(s1[i].size())+1),min((int)(t1.size()-1),start+(int)(s1[i].size())-1)){
				bool f=1;
				rep(k,j,j+(int)(s1[i].size())-1){
						cout<<i<<" "<<j<<" "<<k<<"\n";
						cout<<t1[k]<<" "<<s1[i][k-j+1]<<" "<<t1[k]<<" "<<s1[i][k-j+1]<<"\n";
					if(t1[k]!=s1[i][k-j+1]||t2[k]!=s2[i][k-j+1]){
						cout<<i<<" "<<j<<" "<<k<<"\n";
						f=0;
						break;
					}
				}
				if(f==1){
					flag=1;
					break;
				}
			}
			cout<<i<<" "<<flag<<"\n";
			if(flag==1) ++res;
		}
		cout<<res<<"\n";
	}
}
