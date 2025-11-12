#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ya{
	string s1,s2;
};
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout); 
	int n,q,ans;
	string que,da; 
	cin>>n>>q;
	ya a[n];
	for(int i=0;i<n;++i)cin>>a[i].s1>>a[i].s2;
	while(q--){
		ans=0;
		cin>>que>>da;
		char def[que.size()][2];
		int wei=0,defr[que.size()];
		for(int i=0;i<que.size();++i){
			if(que[i]!=da[i]){
				def[wei][0]=que[i];
				def[wei][1]=da[i];
				defr[wei]=i;
				wei++;
			}
		}
		for(int i=0;i<que.size();++i){
			if(a[i].s1.size()<defr[wei]-defr[0])continue;
			else {
				if(a[i].s1.size()==defr[wei]-defr[0]){
					
					bool pd=0;
					for(int j=defr[0];j<=defr[wei];++j){
						if(que[j]!=a[i].s1[j-defr[0]]){
							pd=1;break;
						}
						if(da[j]!=a[i].s2[j-defr[0]]){
							pd=1;break;
						}
					}
					if(pd==0){
						ans++;
					}
				}
				if(a[i].s1.size()>defr[wei]-defr[0]){
					int pd=0;
					for(int j=defr[0]*2-a[i].s1.size();j<=defr[wei]+a[i].s1.size()-defr[0];++j){
						pd++;
						if(que[j]!=a[i].s1[j-defr[0]]&&da[j]!=a[i].s2[j-defr[0]]){
							pd=0;
						}
					}
					if(pd==defr[wei]-defr[0]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}