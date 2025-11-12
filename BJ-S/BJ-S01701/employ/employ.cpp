#include <bits/stdc++.h>
#include <map>

using namespace std;
char h[505];
int c[505];
int t[505],num[505],tot=0;
long long ans=0;
long long x(long long ttt){
	if(ttt==1 || ttt==0)return 1;
	if(ttt==2)return 2;
	return ttt*x(ttt-1);
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	getchar();
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++){
		h[i]=getchar();
		if(h[i]=='1')t[tot++]=i;
	}
	getchar();
	for(int i=0;i<n;i++)cin>>c[i];
	if(n>20)cout<<0;
	else{
		for(int k=0;k<tot;k++){
		int cnt=0,ans1=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<tot-1;j++){
				if(c[i]>=t[j-k] && c[i]<t[j-1-k]){
					if(num[j]==0)cnt++;
					num[j]++;
				}
			}
		}
		if(cnt>=m)for(int i=0;i<tot;i++){if(num[i]!=0)ans1*=num[i];}
		ans=(ans+ans1*x(m-cnt))%998244353;
		for(int j=1;j<m-cnt;j++){ans1=1; for(int i=j;i<tot;i++){ans1*=num[i];} ans=(ans+ans1*x(m-cnt+j))%998244353;}
		}
		
		cout<<ans%998244353;
	}
			
	return 0;
}
