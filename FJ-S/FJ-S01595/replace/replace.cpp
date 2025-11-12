#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		int s=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int q=x.find(s1[i]),w=y.find(s2[i]);
			int qq=x.find(s1[i]+s1[i]),ww=y.find(s2[i]+s2[i]);
			if(q==w&&q!=-1&&qq==-1&&ww==-1) s++;
		}
		cout<<s<<'\n';
	}
	return 0;
}
