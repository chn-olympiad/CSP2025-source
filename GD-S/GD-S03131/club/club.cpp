#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
struct node{
	int a,b,c,id;
}a[N];
int max(int a,int b){
	return a>b?a:b;
}
int f[N],n,A,B,C,g[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		A=0,B=0,C=0; 
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			a[i].id=i;
			if(a[i].a>a[i].b&&a[i].a>a[i].c)f[i]=1,A++;
			if(a[i].b>a[i].c&&a[i].b>a[i].a)f[i]=2,B++;
			if(a[i].c>a[i].a&&a[i].c>a[i].b)f[i]=3,C++;
		}
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(f[i]==1)sum+=a[i].a;
			if(f[i]==2)sum+=a[i].b;
			if(f[i]==3)sum+=a[i].c;
		}
		if(A<=n/2&&B<=n/2&&C<=n/2){
			cout<<sum<<"\n";
			continue;
		}
		if(A>=n/2){
			for(int i=1;i<=n;i++){
				if(f[i]==1){
					g[++cnt]=a[i].a-max(a[i].b,a[i].c);
				}
			}
			sort(g+1,g+A+1,greater<int>());
			for(int i=n/2+1;i<=A;i++)
			sum-=g[i];
			cout<<sum<<"\n";
		}
		if(B>=n/2){
			for(int i=1;i<=n;i++){
				if(f[i]==2){
					g[++cnt]=a[i].b-max(a[i].a,a[i].c);
				}
			}
			sort(g+1,g+B+1,greater<int>());
			for(int i=n/2+1;i<=B;i++)
			sum-=g[i];
			cout<<sum<<"\n";
		}
		if(C>=n/2){
			for(int i=1;i<=n;i++){
				if(f[i]==3){
					g[++cnt]=a[i].c-max(a[i].b,a[i].a);
				}
			}
			sort(g+1,g+C+1,greater<int>());
			for(int i=n/2+1;i<=C;i++)
			sum-=g[i];
			cout<<sum<<"\n";
		}
	}
	return 0;
} 
/*
Luoge Uid : 695750 
fu le , xie le yi da chuan quan jia diao le
ei bu dui bu dui,ei dui de dui de ,ei !? bu dui bu dui,o quan dui!
lu shi chuan shuo tai hao wan na!
bu shi ge me wo daodi na jia le a
jiu zhi you da yang li mei guo le
te shu xing zhi C zhe me ba wo ka diao de 
suan le suan le ,gu fen :90+0+(0~5)+4
zhe ci de ti mu mei de pen ,que shi bi zhi qian yao nan yi dian
jin nian de checker he qu nian hao xiang bu tai yi yang you dian nan shou
1 
4 
0 1 0
0 1 0
0 2 0
0 2 0
*/
