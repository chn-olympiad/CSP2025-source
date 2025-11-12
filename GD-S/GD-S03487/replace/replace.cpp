#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<pair<string,string> >rep(n+1);
	for(int i=1;i<=n;i++){
		cin>>rep[i].first>>rep[i].second;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int l = a.length();
		long long ans=0;
		if(l<=20){
		for(int i = 1;i <= n;i++){
			int stat = 0;
			for(int j = 0;j < l;j++){
				int t = j;
				if(!stat && a[j] == rep[i].first[0]){
					bool isame = 1;
					for(;t<j + rep[i].first.length();t++){
						if(a[t]!=rep[i].first[t - j]){
							isame = 0;
							break;
						}
						if(rep[i].first[t - j] != b[t]){
							isame = 0;
							break;
						}
					}
					if(isame)stat = 1, j = t;
				}
				else{
					bool isame = 1;
					for(int t = j;t <= l;t++){
						if(a[t]!=b[t]){
							isame = 0;
							break;
						}
					}
					if(isame)ans++;
				}
			}
		}
		cout<<ans<<'\n';
		}else cout<<"0\n";
	}
	return 0;
}
