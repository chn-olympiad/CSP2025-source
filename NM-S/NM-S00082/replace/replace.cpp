#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string x=" ",y=" ",z=" ";
struct node{
	string a,b;
}s[200005];
int found(string ta,string tb){
	for(int i=1;i<=n;i++){
		if(s[i].a==ta&&s[i].b==tb)
			return i;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(q--){
		string sta,stb;
		cin>>sta>>stb;
		int t=found(sta,stb);
		if(t==0){
			cout<<0<<endl;
			continue;
		}
		int l1=sta.size(),l2=stb.size();
		int l=max(l1,l2);
		bool XtoZ=0;
		ans++;
		for(int i=1;i<=l;i++){
			if(sta[i]==stb[i]&&!XtoZ)
				x+=sta[i];
			else if(sta[i]==stb[i]&&XtoZ)
				z+=sta[i];
			else y+=sta[i];
		}
		if(y!=" ")ans++;
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
