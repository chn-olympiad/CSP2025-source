#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i = 1;i <= m;i++){
		string h,h1,s1;
		int ans = 0;
		cin>>h>>h1;
		for(int i = 0;i < m;i++){
			for(int j = 1;j <= n;j++){
				if(h[i] == a[j][0]){
					s1 = h;
					bool st = 0;
					for(int k = 0;k < a[j].size();k++){
						if(i + k < m&&a[j][k] != h[i + k]&&b[j][k] != h1[i + k]){
							s1[i + k] = b[j][k];
						}
						else {
							st = 1;
							break;
						}
					}
					if(!st&&s1 == h1) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
return 0;
}
