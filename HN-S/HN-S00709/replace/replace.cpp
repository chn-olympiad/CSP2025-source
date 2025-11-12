#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1[200010],s2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int siz=t1.size(),ans=0;
		for(int j=1;j<=n;j++){
			string t3=t1;
			int tem=t1.find(s1[j]);
			for(int l=tem;l<tem+s2[j].size();l++){
				t3[l]=s2[j][l-tem];
			}
			//cout<<t3<<' '<<t2<<endl;
			if(t3==t2){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
return 0;}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
