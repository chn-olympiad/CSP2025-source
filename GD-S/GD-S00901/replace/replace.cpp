#include<bits/stdc++.h>
using namespace std;
int n,q;
struct mode{
	string s1;
	string s2;
}s[200007];
/*cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			ka=ka+m[i].a;
			kb=kb+m[i].b;
			kc=kc+m[i].c;
		}
		if(ka>=kb&&ka>=kc) sort(m+1,m+n+1,cmpa);
		else if(kb>=ka&&kb>=kc) sort(m+1,m+n+1,cmpb);
		else if(kc>=kb&&kc>=ka) sort(m+1,m+n+1,cmpc);
		for(int i=1;i<=n;i++){
			if(m[i].a>=m[i].b&&m[i].a>=m[i].c&&op1<n/2){
				op1++;
				sum=sum+m[i].a;
			}
			*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].s1>>s[i].s2;
	}
	cout<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
