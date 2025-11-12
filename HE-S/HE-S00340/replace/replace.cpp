#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	string s1,s2;
}a[1010101];
int n,q;
int ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		string ss1,ss2;
		cin>>ss1>>ss2;
		ans=0;
		if(ss1.size()!=ss2.size()){
			cout<<"0\n";
		}
		else{
			for(int i=1;i<=n;i++){
				string sss1=ss1;
				int ui=sss1.find(a[i].s1);
				if(ui!=-1){
					sss1.erase(ui,a[i].s1.size());
					sss1.insert(ui,a[i].s2);
					if(sss1==ss2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	
	
	
	
	return 0;
}//时代少年团 我们喜欢你 
