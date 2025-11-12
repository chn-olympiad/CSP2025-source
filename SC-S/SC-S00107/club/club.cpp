#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int mi[100005];
int maxn[100005];
int ch[4];
long long sum;
int p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		sum=0;
		ch[1]=ch[2]=ch[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]>a[i][1]){
				if(a[i][3]>a[i][2]){
					maxn[i]=3;
					mi[i]=a[i][3]-a[i][2];
				}else if(a[i][3]>a[i][1]){
					maxn[i]=2;
					mi[i]=a[i][2]-a[i][3];
				}else{
					maxn[i]=2;
					mi[i]=a[i][2]-a[i][1];
				}
			}else{
				if(a[i][3]>a[i][1]){
					maxn[i]=3;
					mi[i]=a[i][3]-a[i][1];
				}else if(a[i][3]>a[i][2]){
					maxn[i]=1;
					mi[i]=a[i][1]-a[i][3];
				}else{
					maxn[i]=1;
					mi[i]=a[i][1]-a[i][2];
				}
			}
			sum+=a[i][maxn[i]];
			ch[maxn[i]]++;
		}
		int k=0,top=1;
		if(ch[1]>(n/2)){
			k=ch[1]-n/2;
			for(int i=1;i<=n;i++){
				if(maxn[i]==1){
					p[top]=mi[i];
					top++;
				}
			}
			if(top!=(ch[1]+1)){
				printf("error");
			}
		}
		if(ch[2]>(n/2)){
			k=ch[2]-n/2;
			for(int i=1;i<=n;i++){
				if(maxn[i]==2){
					p[top]=mi[i];
					top++;
				}
			}
			if(top!=(ch[2]+1)){
				printf("error");
			}
		}
		if(ch[3]>(n/2)){
			k=ch[3]-n/2;
			for(int i=1;i<=n;i++){
				if(maxn[i]==3){
					p[top]=mi[i];
					top++;
				}
			}
			if(top!=(ch[3]+1)){
				printf("error");
			}
		}
		sort(p+1,p+top);
		for(int i=1;i<=k;i++){
			sum-=p[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}