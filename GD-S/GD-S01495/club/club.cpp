#include<bits/stdc++.h>
using namespace std;
struct node{
	int p,hk1,hk2,hk3;
}a[100010];
bool cmp(node x,node y){
	int oo=0,pp=0;
	if(x.hk1==0) oo++;
	if(x.hk2==0) oo++;
	if(x.hk3==0) oo++;
	if(y.hk1==0) pp++;
	if(y.hk2==0) pp++;
	if(y.hk3==0) pp++;
	if(oo!=pp) return oo>pp;
	else return max(x.hk1,max(x.hk2,x.hk3))>max(y.hk1,max(y.hk2,x.hk3));
}
int t,n;
long long sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].hk1,&a[i].hk2,&a[i].hk3);
			a[i].p=0;
		}
		int aa=0,bb=0,cc=0;
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].hk1<<" "<<a[i].hk2<<" "<<a[i].hk3<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(a[i].hk1>a[i].hk2&&a[i].hk1>a[i].hk3){
				if(aa<n/2){
					aa++;
					sum+=a[i].hk1;
					continue;
				}
				else if(a[i].hk2>a[i].hk3){
					if(bb<n/2){
						bb++;
						sum+=a[i].hk2;
						continue;
					}
				}
				cc++;
				sum+=a[i].hk3;
			}
			else if(a[i].hk2>a[i].hk1&&a[i].hk2>a[i].hk3){
				if(bb<n/2){
					bb++;
					sum+=a[i].hk2;
					continue;
				}
				else if(a[i].hk1>a[i].hk3){
					if(aa<n/2){
						aa++;
						sum+=a[i].hk1;
						continue;
					}
				}
				cc++;
				sum+=a[i].hk3;
			}
			else{
				if(cc<n/2){
					cc++;
					sum+=a[i].hk3;
					continue;
				}
				else if(a[i].hk1>a[i].hk2){
					if(aa<n/2){
						aa++;
						sum+=a[i].hk1;
						continue;
					}
				}
				bb++;
				sum+=a[i].hk2;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}/*
考试近结束，发现t1思路错
 最无奈o.O*/ 


