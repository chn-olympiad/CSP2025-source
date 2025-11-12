#include<bits/stdc++.h>
using namespace std;
int n,m,d[505],c[505],b[505],day[505],q1[505];
long long ans;
string s;
void dfs(int j,int cnt,int t){
	day[j]=t;
	if(cnt==n){
		int da=0,ye=0;
		for(int i=1;i<=n;i++){
			if(!d[i]||da>=c[day[i]]){
				da++;
			}else{
				ye++;
			}
		}
		if(ye>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(q1[i])continue;
		q1[i]=1;
		dfs(i,cnt+1,t+1);
		q1[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++)d[i+1]=(int)s[i]-48;
	for(int i=1;i<=n;i++){
		q1[i]=1;
		dfs(i,1,1);
		q1[i]=0;
	}
	cout<<ans%998244353;
	return 0;
 } 
