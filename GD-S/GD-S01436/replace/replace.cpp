#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
bool check(string a,string b,string c,string d){
	for (int j=0;j<(int)c.size();j++){
		if (a[0]==c[j]){
			for (int i=0;i<(int)a.size();i++){
				if (a[i]!=c[j+i]||j+i>=(int)c.size())break;
				if (i==(int)a.size()-1){
					string t=c;
					for (int p=0;p<(int)a.size();p++){
						t[j+p]=b[p];
					}
					if (t==d)return true;
				}
			}
		}
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		int ans=0;
		string S1,S2;
		cin>>S1>>S2;
		for (int i=1;i<=n;i++){
			if (check(s1[i],s2[i],S1,S2))ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
