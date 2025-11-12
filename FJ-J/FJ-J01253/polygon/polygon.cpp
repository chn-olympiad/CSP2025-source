#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const unsigned int mod=998244353;
int ans,cnt[5005],a[5005],n;
void judge(int m){    //in order
	for(int i=1;i<=n-m+1;i++){
		memset(cnt,0,sizeof(cnt));
		int c=1;
		cnt[i]+=a[i];
		for(int j=i+1;j<=n-1;j++)
		{
			cnt[i]+=a[j], c++;
			for(int k=j+1;k<=n;k++){
				cnt[i]+=a[k]; c++;
				if(c==m){
					c--;
					if(cnt[i]>a[k]*2) ans++;
					cnt[i]-=a[k];
				}
			}
			cnt[i]-=a[j];
		}
	}
	ans%=mod;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int m=3;m<=n;m++) judge(m);
	cout<<ans%mod<<endl;
	return 0;
}