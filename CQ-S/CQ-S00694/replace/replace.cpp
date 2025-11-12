#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,q,cnt;
string st[210000][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) cin>>st[i][0]>>st[i][1];
	for(int j=0;j<q;j++){
		cnt=0;
		int b=1,c;
		string s1,s2,s;
		cin>>s1>>s2;
		for(int i=0;i<=s1.size()-st[i][0].size();i++){
			int a=1;
			string ss;
			for(int k=i;k<=i+st[i][0].size()+1;k++){
				ss+=s1[k];
			}
			for(int kk=0;kk<n;kk++){
				if(ss==st[kk][0]){
					s=s1;
					int m=0;
					for(int k=i;k<st[kk][0].size()+i;k++){
						s[k]=st[kk][1][m++];
					}
					if(s==s2) cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
