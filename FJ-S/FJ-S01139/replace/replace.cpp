#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string s[1005],ss[1005];
string t,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,ans=0;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i] >> ss[i];
	}
	for(int i=1;i<=q;i++){
		cin >> t >> tt;
		int tl=t.size(),ttl=tt.size();
		if(tl!=ttl){
			ans=0;
		}else{
			for(int i=1;i<=n;i++){
				if(t==s[i] && tt==ss[i]){
					ans=1;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
