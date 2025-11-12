#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
#define gc getchar()
void read(int &n){int l=1,num;char ch;
while(ch=gc,ch>'9'||ch<'0')if(ch=='-')l=-1;
num=ch-'0';while(ch=gc,ch<='9'&&ch>='0')
num=num*10+ch-'0';n=num*l;return;}

int n,q;
string s[N][11];

signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>q;for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	
	while(q--){
		string t1,t2;cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<t1.length()-s[i][1].length()+1;j++){
				int flag=1;
				for(int k=0;k<s[i][1].length();k++){
					if(t1[j+k]!=s[i][1][k]||t2[j+k]!=s[i][2][k]){
						flag=0;break;
					}
				}
				if(flag){
					for(int k=j+s[i][1].length();k<t1.length();k++){
						if(t1[k]!=t2[k]){
							flag=0;break;
						}
					}
				}
				if(flag)ans++;
				else if(t1[j]!=t2[j])break;
			}
		}cout<<ans<<endl;
	}
	return 0;
}
//kmp²»»áÐ´quq 

