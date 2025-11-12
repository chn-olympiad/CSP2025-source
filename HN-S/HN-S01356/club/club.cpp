#include <bits/stdc++.h>
using namespace std;
int n,t;
int ma,i1,i2,i3,sum,mi=999;
struct node{
	int m1,m2,m3,p,b;
}a[100010];
bool cmp1(node x,node y){
	return x.m1>y.m1;
}
bool cmp2(node x,node y){
	return x.m2>y.m2;
}
bool cmp3(node x,node y){
	return x.m3>y.m3;
}
int A1(int x){
	sort(a,a+n,cmp1);
	for(int i=0;i<x;i++){
	if(a[i].m1==max(a[i].m1,max(a[i].m2,a[i].m3))&&a[i].p==0&&i1<n/2){
		a[i].b=1;
		a[i].p=1;
		i1++;	
	}}
}
int A2(int x){
	sort(a,a+n,cmp2);
	for(int i=0;i<x;i++){
	if(a[i].m2==max(a[i].m1,max(a[i].m2,a[i].m3))&&a[i].p==0&&i2<n/2){
		a[i].b=2;
		a[i].p=1;
		i2++;	
	}}
}
int A3(int x){
	sort(a,a+n,cmp3);
	for(int i=0;i<x;i++){
	if(a[i].m3==max(a[i].m1,max(a[i].m2,a[i].m3))&&a[i].p==0&&i3<n/2){
		a[i].b=3;
		a[i].p=1;
		i3++;
	}}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ma=0;i1=0;i2=0;i3=0;sum=0;mi=999;
		cin>>n;
		ma=n/2;
		for(int i=0;i<n;i++) cin>>a[i].m1>>a[i].m2>>a[i].m3;
		A1(n);A2(n);A3(n);
		for(int i=0;i<n;i++){
			if(a[i].b==1){
				sum+=a[i].m1;
			}
			if(a[i].b==2){
				sum+=a[i].m2;
			}
			if(a[i].b==3){
				sum+=a[i].m3;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
