#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string q1,q2;
string s1[200005],s2[200005];
void check(string u,string v){
	int len=q1.size()-u.size()+1;
	for(int i=0;i<len;i++){
		int kkk=1;
		for(int j=0;j<i;j++)
			if(q1[j]!=q2[j]){
				kkk=0;
				break;
			}
		if(kkk==0) continue;
		for(int j=0,k=i;j<u.size();j++,k++){
			if(u[j]!=q1[k]||v[j]!=q2[k]){
				kkk=0;
				break;
			}
		}
		if(kkk==0) continue;
		for(int j=i+u.size()+1;j<q1.size();j++)
			if(q1[j]!=q2[j]){
				kkk=0;
				break;
			}
		ans+=kkk;	
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		cin>>q1>>q2;
		int l1=q1.size(),l2=q2.size();
		if(l1!=l2){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			check(s1[i],s2[i]);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
