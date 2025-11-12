#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
int n,q;
string t1,t2,s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1.find(s1[i])!=s1[i].npos||t2.find(s1[i])!=s1[i].npos)continue;
			else if(t1.find(s1[i])==t2.find(s2[i])){
				string l1=t1,l2=t2;
				if(l1==l2)ans++;
			}
		}
		cout<<ans<<endl;
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
