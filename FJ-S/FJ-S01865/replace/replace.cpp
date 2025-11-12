#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s1[1010],s2[1010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,q,res=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		res=0;
		for(int i=1;i<=n;i++){
			int ps=0,pt=0;
			while(pt<t1.size()){
				while(ps<s1[i].size()&&pt<t1.size()&&s1[i][ps]==t1[pt]&&s2[i][ps]==t2[pt])ps++,pt++;
				if(ps==s1[i].size()-1){
					res++;
					//cout<<s1[i]<<' '<<s2[i]<<endl;
				}
				ps=0;
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
