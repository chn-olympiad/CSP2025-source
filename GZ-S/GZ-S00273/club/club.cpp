//GZ-S00273
//¹óÑôÒ»ÖĞ Ñî¾ûº­
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n,ans,sum[4];
struct qp{
	int mx1,mx2,xb1,xb2;
}a[N];
bool cmp(qp q,qp p){
	return q.mx1-q.mx2>p.mx1-p.mx2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=sum[1]=sum[2]=sum[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int s[3],x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			s[0]=x,s[1]=y,s[2]=z;
			sort(s,s+3);
			a[i].mx1=s[2],a[i].mx2=s[1];
			if(x==s[2])	a[i].xb1=1;
			else if(y==s[2])	a[i].xb1=2;
			else	a[i].xb1=3;
			if(a[i].xb1!=1 && x==s[1])	a[i].xb2=1;
			else if(a[i].xb1!=2 && y==s[1])	a[i].xb2=2;
			else	a[i].xb2=3;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(sum[a[i].xb1]==n/2){
				sum[a[i].xb2]++;
				ans+=a[i].mx2;
			}
			else{
				sum[a[i].xb1]++;
				ans+=a[i].mx1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

