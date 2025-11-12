#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10],ans,s1,s2,s3;
struct node{
	int id,x;
}m[100005];
int cmp1(struct node n1,struct node n2){
	if(n1.id==1&&n2.id==1)return n1.x<n2.x;
	else if(n2.id==1)return 0;
}
int cmp2(struct node n1,struct node n2){
	if(n1.id==2&&n2.id==2)return n1.x<n2.x;
	else if(n2.id==2)return 0;
}
int cmp3(struct node n1,struct node n2){
	if(n1.id==3&&n2.id==3)return n1.x<n2.x;
	else if(n2.id==3)return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0,s1=0,s2=0,s3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				m[i].id=1;
				m[i].x=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				ans+=a[i][1];
				s1++;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				m[i].id=2;
				m[i].x=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				ans+=a[i][2];
				s2++;
			}else{
				m[i].id=3;
				m[i].x=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
				ans+=a[i][3];
				s3++;
			}
		}
		if(s1>n/2){
			sort(m+1,m+1+n,cmp1);
			for(int i=1;i<=s1-n/2;i++){
				ans-=m[i].x;
			}
		}else if(s2>n/2){
			sort(m+1,m+1+n,cmp2);
			for(int i=1;i<=s2-n/2;i++){
				ans-=m[i].x;
			}
		}else if(s3>n/2){
			sort(m+1,m+1+n,cmp3);
			for(int i=1;i<=s3-n/2;i++){
				ans-=m[i].x;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}