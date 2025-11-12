#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m,c[N],ans,s1[N],cnt;
char s[N];
bool f[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	//for(int i=1;i<=n;i++)s1[i]=s1[i-1]+c[i];
		int v[2][n*2];
		for(int k=1;k<=n;k++)s1[k]=c[k];
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&s1[i]>0){
				v[1][i]=i;
				cnt++;
				if(cnt==m){
					ans++;
					cnt=0;
				}
				for(int j=1;j<=n;j++){
					s1[i]-=1;
				}
			}
		}
	
	cout<<ans;
	return 0;
}
