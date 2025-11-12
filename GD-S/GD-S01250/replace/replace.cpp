#include <bits/stdc++.h>
using namespace std;
const int LEN=1e6+5;
int n,s,q;
string as,bs,s1[LEN],s2[LEN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while (q--){
		cin>>as>>bs;
		int i=0,j=as.size()-1,ans=0;
		for (int i=0,j=as.size()-1;i<=j;){
			string a="",b="";
			for (int k=i;k<=j;k++)a+=as[k],b+=bs[k];
//			cout<<a<<' '<<b<<"ee\n";
			for (int k=1;k<=n;k++){
				if (a==s1[k] && b==s2[k])ans++;
			}
//			if (as[i]!=bs[i] || as[j]!=bs[j])break;
			if (as[i]!=bs[i] && as[j]!=bs[j])break;
			if (as[i]==bs[i])i++;
			if (as[j]==bs[j])j--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
//3 4
//a b
//b c
//c d
//aa bb
//aa b
//a c
//b a
