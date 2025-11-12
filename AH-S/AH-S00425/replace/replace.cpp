#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
struct mixture{
	string s1,s2;
}m[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>m[i].s1>>m[i].s2;
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		string t=a;
		ans=0;
		for(int i=1;i<=n;i++){
			int len1=m[i].s1.size();
			int p=t.find(m[i].s1);
			if(p!=-1){
				for(int j=p;j<len1+p;j++){
					t[j]=m[i].s1[j-p];
				}
				if(t==b)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
