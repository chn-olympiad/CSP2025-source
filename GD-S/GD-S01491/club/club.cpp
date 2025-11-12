#include <bits/stdc++.h>
using namespace std;
struct node{
	int a1;
	int a2;
	int a3;
}a[100010];
int t,n;
bool cmp(node x,node y){
	if(x.a1==y.a1){
		if(x.a2==y.a2)
			return x.a3>y.a3;
		else
			return x.a2>y.a2; 
	}
	else
		return x.a1>y.a1;
}
int main(){
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		long long sum1=0,sum2=0,sum3=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		int k=1;
		while(max(a[k].a1,max(a[k].a2,a[k].a3))==a[k].a1&&sum1<=n/2){
			sum+=a[k].a1;
			k++;
			sum1++;
			if(a[k-1].a2>a[k-1].a3&&a[k-1].a2+a[k].a1>a[k-1].a1&&sum2<n/2&&sum1>=n/2&&(k+1>n||max(a[k+1].a1,max(a[k+1].a2,a[k+1].a3))==a[k+1].a1)){
				sum1--;
				sum2++;
				sum-=a[k-1].a1;
				sum+=a[k-1].a2;
			}
			else if(a[k-1].a2<=a[k-1].a3&&a[k-1].a3+a[k].a1>a[k-1].a1&&sum3<n/2&&sum1>=n/2&&(k+1>n||max(a[k+1].a1,max(a[k+1].a2,a[k+1].a3))==a[k+1].a1)){
				sum1--;
				sum3++;
				sum-=a[k-1].a1;
				sum+=a[k-1].a3;
			}
		}
		for(int i=k;i<=n;i++){
			if(a[i].a2>a[i].a3&&sum2<n/2){
				sum2++;
				sum+=a[i].a2;
				}
			else{
				sum3++;
				sum+=a[i].a3;
			}
			if(a[i-1].a2>a[i-1].a3&&a[i-1].a3+a[i].a2>a[i-1].a2&&sum2<n/2&&sum3>n/2){
				sum3--;
				sum-=a[i-1].a3;
				sum2++;
				sum+=a[i-1].a2;
			}
			else if(a[i-1].a2<=a[i-1].a3&&a[i-1].a2+a[i].a3>a[i-1].a3&&sum3<n/2&&sum2>n/2){
				sum2--;
				sum-=a[i-1].a2;
				sum3++;
				sum+=a[i-1].a3;
			}
		}
		
		cout<<sum<<endl;
	}
	return 0;
} 
