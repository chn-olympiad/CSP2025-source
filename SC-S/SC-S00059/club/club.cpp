#include<bits/stdc++.h>
#define int long long
using namespace std;
struct rnfmabj{
	int zhi,wei;	
}a[1000005],b[1000005],c[1000005];
int num1,num2,num3;
int d[10000005];
int st[1000005][4];
bool cmp(rnfmabj x,rnfmabj y){x.zhi<y.zhi;}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++){
		int n;
		scanf("%lld",&n);
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&st[i][1],&st[i][2],&st[i][3]);
			if(st[i][1]>st[i][2]&&st[i][1]>st[i][3]) a[++num1].wei=i,a[num1].zhi=st[i][1];
			else if(st[i][2]>st[i][3]&&st[i][2]>st[i][1]) b[++num2].wei=i,b[num2].zhi=st[i][2];
			else c[++num3].wei=i,c[num3].zhi=st[i][3];
		}
		int ans1=0,ans2=0,ans3=0;
		for(int i=1;i<=num1;i++) ans1=ans1+st[a[i].wei][1];
		for(int i=1;i<=num2;i++) ans2=ans2+st[b[i].wei][2];
		for(int i=1;i<=num3;i++) ans3=ans3+st[c[i].wei][3];
		if(num1>n/2){
			for(int i=1;i<=num1;i++){
				if(st[a[i].wei][2]>st[a[i].wei][3]&&num2<n/2) d[i]=st[a[i].wei][1]-st[a[i].wei][2];
				else d[i]=st[a[i].wei][3]-st[a[i].wei][1];
			}
			sort(d+1,d+num1+1);
			for(int i=1;i<=num1-n/2;i++){ans1-=d[i];}
			num1=n/2;
		}
		if(num2>n/2){
			for(int i=1;i<=num2;i++){
				if(st[b[i].wei][1]>st[b[i].wei][3]&&num1<n/2) d[i]=st[b[i].wei][2]-st[b[i].wei][1];
				else d[i]=st[b[i].wei][2]-st[b[i].wei][3];
			}
			sort(d+1,d+num2+1);
			for(int i=1;i<=num2-n/2;i++){ans2-=d[i];}
			num2=n/2;
		}
		if(num3>n/2){
			for(int i=1;i<=num3;i++){
				if(st[c[i].wei][1]>st[c[i].wei][2]&&num1<n/2) d[i]=st[c[i].wei][3]-st[c[i].wei][1];
				else d[i]=st[c[i].wei][3]-st[c[i].wei][2];
			}
			sort(d+1,d+num3+1);
			for(int i=1;i<=num3-n/2;i++){ans3-=d[i];}
			num3=n/2;
		}
		printf("%lld",ans1+ans2+ans3);
		printf("\n");
	}
	return 0;
} 