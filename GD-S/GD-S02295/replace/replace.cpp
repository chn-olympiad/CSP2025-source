#include<iostream>
#include<map>
using namespace std;
map<string, string>mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i=0;i<n;i++){
		string a, b;
		cin >> a >> b;
		mp[a]=b;
	}
	for(int kk=1;kk<=q;kk++){
		int ans=0;
		string a, b;
		cin >> a >> b;
		int l=0, r=a.size();
		while(a[l]==b[l])l++;
		while(a[r]==b[r])r--;
		for(int i=0;i<=l;i++)for(int j=a.size();j>=r;j--){
			string sa, sb;
			for(int k=i;k<=j;k++){
				sa+=a[k];
				sb+=b[k];
			}
			if(mp[sa]==sb)ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
