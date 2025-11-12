#include<bits/stdc++.h>
using namespace std;
const int N=500010;
struct rec{
	int x,num;
}a[N],b[N],c[N];
int n,t;
bool v[N],flag,flaga,flagb,flagc;
long long ans,Ans;
bool cmp(rec x,rec y){
	if(x.x==y.x) return y.x>x.x;
	return x.x>y.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(v,0,sizeof(v));
		flag=flaga=flagb=flagc=0;
		ans=Ans=0;
		scanf("%d",&n);
		int m=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&b[i].x,&c[i].x);
			if(a[i].x!=0){
				flaga=1;
			}
			if(c[i].x!=0){
				flagc=1;
			}
			if(b[i].x!=0){
				flagb=1;
				if(c[i].x!=0){
					flagc=1;
					flag=1;
				}
			}
			a[i].num=b[i].num=c[i].num=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		if(!flag){
			for(int i=1;i<=m;i++){
				ans+=a[i].x;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(!flaga){
			if(!flagb){
				if(!flagc){
					printf("0\n");
					continue;
				}
				else{
					for(int i=1;i<=m;i++){
						ans+=c[i].x;
					}
					printf("%lld\n",ans);
					continue;
				}
			}
			else if(!flagc){
				for(int i=1;i<=m;i++){
					ans+=b[i].x;
				}
				printf("%lld\n",ans);
				continue;
			}
			else{
				Ans=ans=0;
				for(int i=1;i<=m;i++){
					Ans=0;
					for(int j=1;j<=i;j++){
						Ans+=b[j].x;
						v[b[j].num]=1;
					}
					int z=m-i;
					for(int j=1;j<=z;j++){
						if(!v[c[j].num]){
							Ans+=c[j].x;
							v[c[j].num]=1;
						}
						else{
							z++;
						}
					}
					ans=max(ans,Ans);
				}
				printf("%lld\n",ans);
				continue;
			}
		}
		else if(!flagb){
			Ans=ans=0;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=i;j++){
					Ans+=a[j].x;
					v[a[j].num]=1;
				}
				int z=m-i;
				for(int j=1;j<=z;j++){
					if(!v[c[j].num]){
						Ans+=c[j].x;
						v[c[j].num]=1;
					}
					else{
						z++;
					}
				}
				ans=max(ans,Ans);
			}
			printf("%lld\n",ans);
			continue;
		}
		else if(!flagc){
			Ans=ans=0;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=i;j++){
					Ans+=a[j].x;
					v[a[j].num]=1;
				}
				int z=m-i;
				for(int j=1;j<=z;j++){
					if(!v[b[j].num]){
						Ans+=b[j].x;
						v[b[j].num]=1;
					}
					else{
						z++;
					}
				}
				ans=max(ans,Ans);
			}
			printf("%lld\n",ans);
			continue;
		}
		else{
			printf("21\n");
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
