#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int name;
	int num;
}mx[N],mx1[N];
int t,n,mm[4],so[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(so,0,sizeof(so));
		memset(mm,0,sizeof(mm));
		for(int i=1;i<=n;i++){
			mx[i].num=0;
			mx1[i].num=0;
			for(int j=1;j<=3;j++){
				int a;
				scanf("%d",&a);
				if(mx[i].num<a){
					mx1[i].num=mx[i].num;
					mx1[i].name=mx[i].name;
					mx[i].num=a;
					mx[i].name=j;
				}else if(mx1[i].num<a){
					mx1[i].num=a;
					mx1[i].name=j;
				}
			}
		}
		long long sum=0;
		for(int i=1;i<=n;i++){
			mm[mx[i].name]++;
			sum+=mx[i].num;
		}
		int chong,duo;
		bool tt=true;
		for(int i=1;i<=3;i++){
			if(mm[i]>n/2){
				chong=i;
				duo=mm[i]-n/2;
				tt=false;
			}
		}
		if(tt){
			cout<<sum;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(mx[i].name==chong){
				so[++cnt]=mx[i].num-mx1[i].num;
			}
		}
		sort(so+1,so+1+cnt,cmp);
		for(int i=1;i<=duo;i++){
			sum-=so[i];
		}
		printf("%d\n",sum);
	}
} 
