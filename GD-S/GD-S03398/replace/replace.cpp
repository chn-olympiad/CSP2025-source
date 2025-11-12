#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int N=10010;
string s1[N],s2[N];
int n,q;
bool ys;
int ans;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		ans=0;
		for(int k=1;k<=n;k++){
			for(int i=0;i+s1[k].size()-1<t1.size();i++){
				ys=true;
				for(int j=0;j<s1[k].size();j++){
					if(t1[i+j]!=s1[k][j]){
						ys=false;
						break;
					}
				}
				if(ys){
					for(int j=0;j<s2[k].size();j++){
						if(t2[i+j]!=s2[k][j]){
							ys=false;
							break;
						}
					}
					if(ys)
						ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
