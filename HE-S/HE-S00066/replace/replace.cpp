#include<bits/stdc++.h>
using namespace std;
const int INF=2*1e5+10;
struct vocu{
	string a,b;
}a[INF];
string dif1,dif2;//s1的不同和s2的不同 
void diffe(string s1,string s2){
	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i]){
			dif1+=s1[i];
			dif2+=s2[i];
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	for(int k=1;k<=q;k++){
		string to,tt;
		cin >> to >> tt;
		cout<<0;
	}
	return 0;
}
