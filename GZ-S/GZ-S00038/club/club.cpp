//GZ-S00038 北京师范大学贵阳附属中学 冯俊豪 
#include<bits/stdc++.h>
using namespace std;
int t;
struct l{
	int a1,a2,a3;
	long long cha,maxn,maxi;
}a[100005];
bool cmp(l a,l b){
	if(a.cha==b.cha)return a.maxn>b.maxn;
	else return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].a1==a[i].maxn){
				a[i].maxi=1;
				a[i].cha=max(a[i].maxn-a[i].a2,a[i].maxn-a[i].a3);
				continue;
			}
			if(a[i].a2==a[i].maxn){
				a[i].maxi=2;
				a[i].cha=max(a[i].maxn-a[i].a1,a[i].maxn-a[i].a3);
				continue;
			}
			if(a[i].a3==a[i].maxn){
				a[i].maxi=3;
				a[i].cha=max(a[i].maxn-a[i].a2,a[i].maxn-a[i].a1);
				continue;
			}
		}
		sort(a+1,a+1+n,cmp);
		int sumn=n/2;
		int cnt[4]={};
		for(int i=1;i<=n;i++){
			if(cnt[a[i].maxi]==sumn){
				if(a[i].maxi==1){
					int nmax=max(a[i].a2,a[i].a3);
					if(nmax==a[i].a2){
						sum+=nmax;
						cnt[2]++;
					}else{
						sum+=nmax;
						cnt[3]++;
					}
				}
				if(a[i].maxi==2){
					int nmax=max(a[i].a1,a[i].a3);
					if(nmax==a[i].a1){
						sum+=nmax;
						cnt[1]++;
					}else{
						sum+=nmax;
						cnt[3]++;
					}
				}
				if(a[i].maxi==3){
					int nmax=max(a[i].a2,a[i].a1);
					if(nmax==a[i].a2){
						sum+=nmax;
						cnt[2]++;
					}else{
						sum+=nmax;
						cnt[1]++;
					}
				}
				continue;
			}
			sum+=a[i].maxn;
			cnt[a[i].maxi]++;
		}
		cout<<sum<<endl;
		memset(a,0,sizeof(a));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
