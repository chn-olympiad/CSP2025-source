#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a1[N],a2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>a1[i]>>a2[i];
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x=s1.find(a1[i]);
			if(x==-1) continue;
			string str=s1;
			for(int j=0,k=x;j<a2[i].size();j++,k++){
				str[k]=a2[i][j];
			}
			//cout<<a1[i]<<" "<<str<<endl;
			if(str==s2) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
