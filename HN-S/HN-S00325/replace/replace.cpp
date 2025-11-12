#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define MAX 5000000
struct node{
	string a,b;
}s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	while(m--){
		int ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
//			cout<<s1.find(s[i].a)<<" "<<s2.find(s[i].b)<<'\n';
			if(s1.find(s[i].a)>MAX||s2.find(s[i].b)>MAX){
				continue;
			}
			else{
				int xb1=s1.find(s[i].a);
				int xb2=s2.find(s[i].b);
				string sf=s1.substr(0,xb1)+s[i].b+s1.substr(xb1+s[i].a.size(),s1.size());
				if(sf==s2){
					if(s[i].a==s[i].b){
						int kf=s1.size();
						int fk=s[i].a.size();
						for(int jg=0;jg<kf;jg++){
							string scv="";
							for(int k=jg;k<jg+fk;k++){
								scv+=s1[k];
							}
							cout<<scv<<' ';
							if(scv==s[i].a){
								ans++;
							}
						}
					}
					else{
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
