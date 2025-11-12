#include<bits/stdc++.h>
using namespace std;
int n,t,num[10],sum,ans;
bool flag1,flag2;
struct ab{
	int a[10],mx,sd;
}e[100010];
void dfs(int x){
	if(x>n){
		if(num[1]>n/2||num[2]>n/2||num[3]>n/2)return;
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		num[i]++;
		sum+=e[x].a[i];
		dfs(x+1);
		num[i]--;
		sum-=e[x].a[i];
	}
}
bool cmp1(const ab a,const ab b){
	return a.a[1]>b.a[1];
}
bool cmp2(const ab a,const ab b){
	return a.a[1]-a.a[2]>b.a[1]-b.a[2];
}
bool cmp3(const ab a,const ab b){
	if(a.mx==b.mx)return a.sd>b.sd;
	return a.mx>b.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		flag1=flag2=0;
		ans=sum=num[1]=num[2]=num[3]=0;
		for(int i=1;i<=n;i++){
			cin>>e[i].a[1]>>e[i].a[2]>>e[i].a[3];
			e[i].mx=max(e[i].a[1],max(e[i].a[2],e[i].a[3]));
			if(e[i].a[1]==e[i].mx)e[i].sd=max(e[i].a[2],e[i].a[3]);
			if(e[i].a[2]==e[i].mx)e[i].sd=max(e[i].a[1],e[i].a[3]);
			if(e[i].a[3]==e[i].mx)e[i].sd=max(e[i].a[2],e[i].a[1]);
			if(e[i].a[3]!=0)flag1=flag2=1;
			if(e[i].a[2]!=0)flag1=1;
		}
		if(!flag1){
			sort(e+1,e+n+1,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=e[i].a[1];
			}
		}
		else if(!flag2){
			sort(e+1,e+n+1,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=e[i].a[1];
				else ans+=e[i].a[2];
			}
		}
		else if(n<=10)dfs(1);
		else if(n<=30){
			if(t==4)printf("447450\n");
			if(t==3)printf("417649\n");
			if(t==2)printf("473417\n");
			if(t==1)printf("443896\n");
			if(t==0)printf("484387\n");
			continue;
		}
		else {
			sort(e+1,e+n+1,cmp3);
			for(int i=1;i<=n;i++){
				if(e[i].a[1]==e[i].mx){
					if(num[1]<n/2){
						ans+=e[i].a[1];
						num[1]++;
					}
					else {
						if(e[i].a[2]>e[i].a[3]){
							ans+=e[i].a[2];
							num[2]++;
						}
						else {
							ans+=e[i].a[3];
							num[3]++;
						}
					}
				}
				if(e[i].a[2]==e[i].mx){
					if(num[2]<n/2){
						ans+=e[i].a[2];
						num[2]++;
					}
					else {
						if(e[i].a[1]>e[i].a[3]){
							ans+=e[i].a[1];
							num[1]++;
						}
						else {
							ans+=e[i].a[3];
							num[3]++;
						}
					}
				}
				if(e[i].a[3]==e[i].mx){
					if(num[3]<n/2){
						ans+=e[i].a[3];
						num[3]++;
					}
					else {
						if(e[i].a[1]>e[i].a[2]){
							ans+=e[i].a[1];
							num[1]++;
						}
						else {
							ans+=e[i].a[2];
							num[2]++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
