#include<bits/stdc++.h>
using namespace std;
int t,n,ans[3],c[3],like[3],y[3],yl[3];
struct Node{
	int l[3],max1,max2,mel,me,min1;
	int inc,inl;
}a[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].l[1]>>a[j].l[2]>>a[j].l[3];
			for(int b=1;b<=3;b++){
				if(a[j].l[b]>a[j].max1){
					a[j].max1=a[j].l[b];
					a[j].max2=b;
				}
				if(a[j].l[b]<a[j].min1){
					a[j].min1=b;
				}
			}
			a[j].me=5-a[j].min1-a[j].max2;
			a[j].mel=a[j].l[1]+a[j].l[2]+a[j].l[3]-min(min(a[j].l[1],a[j].l[2]),a[j].l[3])-a[j].max1;
		}
		for(int j=1;j<=n;j++){
			for(int b=1;b<=3;b++){
				if(a[j].l[b]>like[b]){
					like[b]=a[j].l[b];
					c[b]=b;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(y[j]<n/2){
				a[j].inc=a[j].max2;
				y[j]++;
				a[j].inl=a[j].mel;
				ans[i-1]+=a[j].inl;
			} 
			else{
				a[j].inc=a[j].me;
				a[j].inl=a[j].mel;
				y[a[j].inc]++;
				ans[i-1]+=a[j].inl;
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	} 
	return 0;
} 
