#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct info{
	int s1,s2,s3;
	bool f;
};
bool cmp1(info x,info y){
	return x.s1>y.s1;
}
bool cmp2(info x,info y){
	return x.s2>y.s2;
}
bool cmp3(info x,info y){
	return x.s3>y.s3;
}
int n,t,sum=0,a1=0,a2=0,a3=0;
info a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		sum=0;
		a1=0;
		a2=0;
		a3=0;
		n=0;
		if(i!=1){
			for(int j=1;j<=n;j++){
				a[j].f=false;
				a[j].s1=0;
				a[j].s2=0;
				a[j].s3=0;
			}
		}
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].s1>>a[j].s2>>a[j].s3;
			a[j].f=true;
		}
		sort(a+1,a+n+1,cmp1);
		for(int j=1;j<=n;j++){
			if(max(a[j].s1,max(a[j].s2,a[j].s3))==a[j].s1&&a[j].f){
				a[j].f=false;
				sum+=a[j].s1;
				a1++;
			}
			if(a1>=n/2) break;
		}
		sort(a+1,a+n+1,cmp2);
		for(int j=1;j<=n;j++){
			if(max(a[j].s1,max(a[j].s2,a[j].s3))==a[j].s2&&a[j].f){
				a[j].f=false;
				sum+=a[j].s2;
				a2++;
			}
			if(a2>=n/2) break;
		}
		sort(a+1,a+n+1,cmp3);
		for(int j=1;j<=n;j++){
			if(max(a[j].s1,max(a[j].s2,a[j].s3))==a[j].s3&&a[j].f){
				a[j].f=false;
				sum+=a[j].s3;
				a3++;
			}
			if(a3>=n/2) break;
		}
		cout<<sum<<endl;
	}
	return 0;
}
