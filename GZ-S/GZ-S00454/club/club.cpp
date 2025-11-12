//GZ-S00454 贵阳市清华中学 陈俊仰 
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;


int n,t;
int aa[N][3];
int cnt[3];
long long maxn;
bool flag;
struct node{
	int a,b,c,d,id;
}a[N];
int abs(int a,int b){
	if(a<b){
		return b-a;
	}
	return a-b;
}
bool cmp(node a, node b){
	return abs(a.a,a.b)>abs(b.a,b.b);
}
bool cmp1(node a, node b){
	return abs(a.d,a.c)>abs(b.d,b.c);
}
int check(int x){
	int id=1;
	maxn=a[x].a;
	if(maxn<a[x].b){
		id=2;
		maxn=a[x].b;
	}
	return id;
}
void dfs(int p,long long ans){
	if(p==n+1){
		maxn=max(ans,maxn);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(p+1,ans+aa[p][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		flag=0;
		maxn=0;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>aa[i][j];
			}
			if(aa[i][3]!=0){
				flag=1;
			}
		}
		if(flag||n<200){
			dfs(1,0);
			cout<<maxn<<"\n";
		}
		else{
			for(int i=1;i<=n;i++){
				a[i].a=aa[i][1];
				a[i].b=aa[i][2];
				a[i].c=aa[i][3];
			}
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n;i++){
				int id=check(i);
				if(cnt[id]==n/2){
					if(id==1){
						cnt[2]++;
						a[i].d=a[i].b;
						a[i].id=2;	
					}
					else{
						cnt[1]++;
					}
				}
				else{
					cnt[id]++;
					a[i].d=maxn;
					a[i].id=id;
				}
				
			}
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(cnt[3]==n/2){
					ans+=max(a[i].a,a[i].b); 
				}
				else{
					if(a[i].d>a[i].c){
						ans+=a[i].d;					
					}
					else{
						ans+=max({a[i].c,a[i].a,a[i].b});
						cnt[3]++;
					}
					
				}
				
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
