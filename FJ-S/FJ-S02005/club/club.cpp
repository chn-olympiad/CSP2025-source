#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N][5],b[N];
int b1,b2,b3;
int c[N];
int cnt;
int l[N];
void merge(int L,int R){
	if(L>=R) return;
	int mid=L+R>>1;
	merge(L,mid);
	merge(mid+1,R);
	int i=L,j=mid+1;
	int k=L;
	while(i<=mid and j<=R)
		if(c[i]>=c[j]) l[k++]=c[i++];
		else l[k++]=c[j++];
	while(i<=mid) l[k++]=c[i++];
	while(j<=R) l[k++]=c[j++];
	for(int i=L;i<=R;i++) c[i]=l[i];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0;
		cnt=0;
		b1=b2=b3=0;
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int sum=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==sum){
				b[i]=1;
				b1++;
				ans+=a[i][1];
			}
			else if(a[i][2]==sum){
				b[i]=2;
				b2++;
				ans+=a[i][2];
			}
			else{
				b[i]=3;
				b3++;
				ans+=a[i][3];
			}
		}
		if(b1<=n/2 and b2<=n/2 and b3<=n/2)
			printf("%d\n",ans);
		else{
			if(b1>n/2){
				for(int i=1;i<=n;i++){
					if(b[i]==1){
						cnt++;
						c[cnt]=max(a[i][2],a[i][3])-a[i][1];
					}
				}
				merge(1,cnt);
				for(int i=1;i<=b1-n/2;i++) ans+=c[i];
				printf("%d\n",ans);
			}else if(b2>n/2){
				for(int i=1;i<=n;i++){
					if(b[i]==2){
						cnt++;
						c[cnt]=max(a[i][1],a[i][3])-a[i][2];
					}
				}
				merge(1,cnt);
				for(int i=1;i<=b2-n/2;i++) ans+=c[i];
				printf("%d\n",ans);
			}else{
				for(int i=1;i<=n;i++){
					if(b[i]==3){
						cnt++;
						c[cnt]=max(a[i][2],a[i][1])-a[i][3];
					}
				}
				merge(1,cnt);
				for(int i=1;i<=b3-n/2;i++) ans+=c[i];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
