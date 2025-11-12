#include<bits/stdc++.h>
using namespace std;

int n,q,j1,j2,u,ans;
string t1,t2;
struct str{
	string s1,s2;
	int v;
}a[200007];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		j1=j2=0;
		cin>>a[i].s1>>a[i].s2;
		while(a[i].s1[j1]!='b')j1++;
		while(a[i].s2[j2]!='b')j2++;
		a[i].v=j2-j1;
	}
	while(q--){
		j1=j2=ans=0;
		cin>>t1>>t2;
		while(t1[j1]!='b')j1++;
		while(t2[j2]!='b')j2++;
		u=j2-j1;
		for(int i=1;i<=n;i++){
			if(a[i].v==u)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
