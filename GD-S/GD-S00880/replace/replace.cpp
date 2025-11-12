#include<bits/stdc++.h>
using namespace std;
struct node{
	string a;
	string b;
}d[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>d[i].a>>d[i].b;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string st,tar;
		cin>>st>>tar;
		for(int i=1;i<=n;i++){
			int pos=st.find(d[i].a);
			if(st.find(d[i].a)==-1) continue;
			string now=st;
			now.replace(pos,(d[i].a).size(),d[i].b);
			if(now==tar) ans++;
			cout<<now<<' '<<tar<<"\n";
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

