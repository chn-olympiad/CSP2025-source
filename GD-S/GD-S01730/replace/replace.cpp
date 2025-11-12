#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if((int)t1.size()!=(int)t2.size()){
			printf("0\n");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int a=s[i][0].size(),b=t1.size();
			if(b<a)continue;
			for(int j=0;j<b-a+1;j++){
				int f=1;
				for(int k=0;k<j;k++){
					if(t2[k]!=t1[k]){
						f=0;
						break;
					}
				}
				for(int k=0;k<a;k++){
					if(s[i][0][k]!=t1[j+k]||s[i][1][k]!=t2[j+k]){
						f=0;
						break;
					}
				}
				for(int k=j+a;k<b;k++){
					if(t2[k]!=t1[k]){
						f=0;
						break;
					}
				}
				if(f)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
