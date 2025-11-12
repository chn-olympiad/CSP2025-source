#include <bits/stdc++.h>
using namespace std;
int t,n,f1,f2,f3;
long long sum;
struct node{
	int c[5];
}a[500005],c1[500005],c2[500005],c3[500005];
bool cmp1(node x,node y){
	if(x.c[1]==y.c[1]){
		if(x.c[3]==y.c[3]){
			return x.c[2]<y.c[2];
		}
		return x.c[3]>y.c[3];
	}
	return x.c[1]<y.c[1];
}
bool cmp2(node x,node y){
	if(x.c[2]==y.c[2]){
		if(x.c[3]==y.c[3]){
			return x.c[1]<y.c[1];
		}
		return x.c[3]>y.c[3];
	}
	return x.c[2]<y.c[2];
}
bool cmp3(node x,node y){
	if(x.c[3]==y.c[3]){
		if(x.c[1]==y.c[1]){
			return x.c[2]<y.c[2];
		}
		return x.c[1]>y.c[1];
	}
	return x.c[3]<y.c[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n>2){
			f3=f2=f1=1;
			sum=0;
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i].c[1]);
				scanf("%d",&a[i].c[2]);
				scanf("%d",&a[i].c[3]);
				if(a[i].c[1]>=a[i].c[2]&&a[i].c[1]>=a[i].c[3]){
					c1[f1++]=a[i];
					sum+=a[i].c[1];
				}
				else if(a[i].c[2]>=a[i].c[1]&&a[i].c[2]>=a[i].c[3]){
					c2[f2++]=a[i];
					sum+=a[i].c[2];
				}
				else{
					c3[f3++]=a[i];
					sum+=a[i].c[3];
				}
			}
			if(f1-1>n/2){
				sort(c1+1,c1+n+1,cmp1);
				for(int i=0;i<f1-1-n/2;i++){
					sum=sum-c1[i].c[1]+max(c1[i].c[2],c1[i].c[3]);
					if(c1[i].c[2]>=c1[i].c[3]){
						c2[f2++]=c1[i];
					}
					else{
						c3[f3++]=c1[i];
					}
				}
			}
			if(f2-1>n/2){
				sort(c2+1,c2+n+1,cmp2);
				for(int i=0;i<f2-1-n/2;i++){
					sum=sum-c1[i].c[2]+max(c1[i].c[1],c1[i].c[3]);
					if(c2[i].c[1]>=c1[i].c[3]){
						c1[f1++]=c2[i];
					}
					else{
						c3[f3++]=c2[i];
					}
				}
			}
			if(f3-1>n/2){
				sort(c3+1,c3+n+1,cmp3);
				for(int i=0;i<f1-1-n/2;i++){
					sum=sum-c1[i].c[3]+max(c1[i].c[1],c1[i].c[1]);
					if(c3[i].c[1]>=c1[i].c[2]){
						c1[f1++]=c3[i];
					}
					else{
						c2[f2++]=c3[i];
					}
				}
			}
		}
		else{
			sum=0;
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i].c[1]);
				scanf("%d",&a[i].c[2]);
				scanf("%d",&a[i].c[3]);
			}
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						sum=max(sum,(long long)(a[1].c[i]+a[2].c[j]));
					}
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
