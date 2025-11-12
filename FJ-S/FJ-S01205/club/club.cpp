#include<bits/stdc++.h>
using namespace std;
int n,t,vis[100005],sum=0,sum1,sum2,flag1,flag2,flag3,flag4;
struct p{
	int mn,per,pla;
}a[300005];
bool cmp(p c,p d){
	return c.mn>d.mn;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			for(int i=1;i<=6;i++){
				cin>>a[i].mn;
				a[i].per=(i+2)/3;
				a[i].pla=i%3;
				if(a[i].pla==0){
					a[i].pla=3;
				}
			}
			sort(a+1,a+1+6,cmp);
			for(int i=0;i<6;i++){
				if(a[i].per==1 && flag1==0){
					sum+=a[i].mn;
					flag1=a[i].pla;
				}else if(a[i].per==2 && flag2==0){
					sum+=a[i].mn;
					flag2=a[i].pla;
				}
			}
			if(flag1!=flag2){
				cout<<sum;
				return 0;
			}else{
				sum1=sum;
				sum2=sum;
				for(int i=0;i<6;i++){
					if(a[i].per==1 && a[i].pla!=flag1 && flag3==0){
						sum1+=a[i].mn;
						flag3=1;
					}else if(a[i].per==1 && a[i].pla==flag1){
						sum1-=a[i].mn;
					}else if(a[i].per==2 && a[i].pla!=flag2 && flag4==0){
						sum2+=a[i].mn;
						flag4=1;
					}else if(a[i].per==2 && a[i].pla==flag2){
						sum2-=a[i].mn;
					}
				}
				cout<<max(sum1,sum2);
			}
		}else{
			for(int i=1;i<=3*n;i++){
				cin>>a[i].mn;
			}
			sort(a+1,a+1+3*n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].mn;
			}
			cout<<sum;
		}
	}
	
	return 0;
}
