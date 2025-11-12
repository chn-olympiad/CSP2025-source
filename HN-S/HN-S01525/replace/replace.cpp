#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],n,q,ans=0;
string s1,s2,s[N][2],s3;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		ans=0;
		for(int j=0;j<s1.size();j++){
			for(int k=1;k<=n;k++){
				if(s1[j]==s[k][0][0]&&s2[j]==s[k][1][0]){
					s3=s1;
					for(int e=0;e<s[k][1].size();e++){
						if(s1[j+e]!=s[k][0][e])break;
						s3[j+e]=s[k][1][e];
					}
					if(s3==s2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//

