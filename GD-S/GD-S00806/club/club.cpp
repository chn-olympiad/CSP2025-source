#include<bits/stdc++.h>
using namespace std;
#define int long long 
int t;
const int N=1e5+4;
int a[N],b[N],c[N];
int sum1[N],sum2[N],sum3[N]; 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i])sum1[++cnt1]=a[i]-max(b[i],c[i]),ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i])sum2[++cnt2]=b[i]-max(a[i],c[i]),ans+=b[i];
			else if(c[i]>=a[i]&&c[i]>=b[i])sum3[++cnt3]=c[i]-max(b[i],a[i]),ans+=c[i];
		}
		sort(sum1+1,sum1+cnt1+1,cmp);
		sort(sum2+1,sum2+cnt2+1,cmp);
		sort(sum3+1,sum3+cnt3+1,cmp);
		if(cnt1>n/2){
			for(int i=n/2+1;i<=cnt1;i++)ans-=sum1[i];
		}
		else if(cnt2>n/2){
			for(int i=n/2+1;i<=cnt2;i++)ans-=sum2[i];
		}
		else if(cnt3>n/2){
			for(int i=n/2+1;i<=cnt3;i++)ans-=sum3[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
先找出每组最大的数，统计最大的数的分布并记录id，如果超出，则反悔 
记录每组中最大差值 
*/
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

