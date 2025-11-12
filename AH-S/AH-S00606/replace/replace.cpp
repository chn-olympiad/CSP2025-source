#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string ed[N][5],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ed[i][1]>>ed[i][2];
	}
	while(q--){
		cin>>s1>>s2;
		int cnt=0,len1=s1.size(),len2=s2.size();
		if(len1!=len2){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			int x=s1.find(ed[i][1]),y=s2.find(ed[i][2]);
			if(x!=y)continue;
			if(x==(-1)&&y==(-1))continue;
			int l=ed[i][1].size();
			if(s1.substr(0,x)!=s2.substr(0,y))continue;
			if(s1.substr(x+l,len1)!=s2.substr(y+l,len2))continue;
			cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
