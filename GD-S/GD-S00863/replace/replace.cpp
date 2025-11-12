#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct node{
	string s1,s2;
}e[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>e[i].s1>>e[i].s2;
	while(q--){
		ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			string t3=t1;
			
			for(int j=0;j<t1.length()-e[i].s1.length();j++){
				int sa=0;
				for(int k=j;k<=j+e[i].s1.length();k++){
					if(t3[k]!=e[i].s1[k-j]){
						sa=1;
						break;
					}
					t3[k]=e[i].s1[k-j];
				}
				if(sa)continue;
				//cout<<t3<<' '<<t2<<endl;
				if(t3==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
