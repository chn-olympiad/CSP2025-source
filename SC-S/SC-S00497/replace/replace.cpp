#include<bits/stdc++.h>
using namespace std;
namespace A{
	int n,q,l,r,ans;
	string s1[200010],s2[200010],a,b,c,t1,t2;
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		for(int i=1;i<=q;i++){
			cin>>t1>>t2;
			ans=0;
			for(int j=1;j<t1.size();j++){
				if(t1[j]!=t2[j]&&l==0){
					l=j;
				}
				if(t1[j]==t2[j]&&l!=0&&r==0){
					r=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(s1[j]==t1&&s2[j]==t2){
					ans++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
}
int main(){
	return A::main();
}