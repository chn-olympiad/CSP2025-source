#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN=1e5+5;
struct node{
	int a1,a2,a3;
}a[100005];
int dp[100005][3];
int f2=0;
int f3=0;
bool cmp1(node a,node b){
	return a.a1>b.a1;
	return a.a2>b.a2;
	return a.a3>b.a3;
}
struct node2{
	int v;
	int i;
};
node2 a1[MAXN];
node2 a2[MAXN];
node2 a3[MAXN];
bool cmp(node2 a,node2 b){
	return a.v>b.v;
}
bool stu[MAXN];
int ansd=-1e9;
void dfs(int t,int sum1,int sum2,int sum3,int sum){
	ansd=max(sum,ansd);
	if(sum1<n/2){
		dfs(t+1,sum1+1,sum2,sum3,sum+a[t].a1);
	}
	if(sum2<n/2){
		dfs(t+1,sum1,sum2+1,sum3,sum+a[t].a2);
	}
	if(sum3<n/2){
		dfs(t+1,sum1,sum2,sum3+1,sum+a[t].a3);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		memset(stu,0,sizeof(stu));
		cin>>n;
		f2=0;
		f3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a1[i].v=a[i].a1;
			a2[i].v=a[i].a2;
			a3[i].v=a[i].a3;
			a1[i].i=i;
			a2[i].i=i;
			a3[i].i=i;
			if(a[i].a2!=0)f2=1;
			if(a[i].a3!=0)f3=1;
		}
		int ans=0;
		if(!f2&&!f3){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n==2){
			cout<<max(max(a[1].a1+a[2].a2,a[1].a1+a[2].a3),max(max(a[1].a3+a[2].a1,a[1].a3+a[2].a2),max(a[1].a2+a[2].a1,a[1].a2+a[2].a3)));
			continue;
		}if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ansd<<'\n';
			continue;
		}
		sort(a1+1,a1+1+n,cmp);
		sort(a2+1,a2+1+n,cmp);
		sort(a3+1,a3+1+n,cmp);
		int sum1=0;
		int sum2=0;
		int sum3=0;
		for(int i=1;i<=n-2;i++){
			if(a1[i].v>=a2[i].v&&a1[i].v>=a3[i].v){
				if(!stu[a1[i].i]&&sum1<n/2){
					sum1++;
					stu[a1[i].i]=1;
					ans+=a1[i].v;
				}
				if(a2[i].v>=a3[i].v){
					if(!stu[a2[i].i]&&sum2<n/2){
						sum2++;
						stu[a2[i].i]=1;
						ans+=a2[i].v;
					}
				}
				if(!stu[a3[i].i]&&sum3<n/2){
					sum3++;
					stu[a3[i].i]=1;
					ans+=a3[i].v;
				}
			}else if(a2[i].v>=a1[i].v&&a2[i].v>=a3[i].v){
				if(!stu[a2[i].i]&&sum2<n/2){
					sum2++;
					stu[a2[i].i]=1;
					ans+=a2[i].v;
				}
				if(a1[i].v>=a3[i].v){
					if(!stu[a1[i].i]&&sum1<n/2){
						sum1++;
						stu[a1[i].i]=1;
						ans+=a1[i].v;
					}
				}
				if(!stu[a3[i].i]&&sum3<n/2){
					sum3++;
					stu[a3[i].i]=1;
					ans+=a3[i].v;
				}
			}
			if(a3[i].v>=a2[i].v&&a3[i].v>=a1[i].v){
				if(!stu[a3[i].i]&&sum3<n/2){
					sum3++;
					stu[a3[i].i]=1;
					ans+=a3[i].v;
				}
				if(a2[i].v>a1[i].v){
					if(!stu[a2[i].i]&&sum2<n/2){
						sum2++;
						stu[a2[i].i]=1;
						ans+=a2[i].v;
					}
				}
				if(!stu[a1[i].i]&&sum1<n/2){
					sum1++;
					stu[a1[i].i]=1;
					ans+=a1[i].v;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
