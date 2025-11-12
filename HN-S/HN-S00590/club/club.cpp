#include<bits/stdc++.h>
using namespace std;
struct xx{
	int a1;
	int a2;
	int a3;
	int a4;
	int a5;
	int a6;
};
xx a[100005];
int cmp(xx x,xx y){
	return x.a1>y.a1;
}
int cmp1(xx x,xx y){
	return x.a2>y.a2;
}
int cmp2(xx x,xx y){
	return x.a3>y.a3;
}
int n,m;
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int m1;
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>m;
		m1=m/2;
		for(int j=0;j<m;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
		}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		a[i].a4=i;
	}
	sort(a,a+m,cmp1);
	for(int i=0;i<m;i++){
		a[i].a5=i;
	}
	sort(a,a+m,cmp1);
	for(int i=0;i<m;i++){
		a[i].a6=i;
	}
	for(int j=0;j<=m;j++){
		if(max(a[j].a1,a[j].a2)==a[j].a1&&max(a[j].a1,a[j].a3)==a[j].a1&&a[j].a4<m1){sum+=a[j].a1;continue;}
		if(max(a[j].a2,a[j].a3)==a[j].a1&&a[j].a4<m1){sum+=a[j].a2;continue;}	
		sum+=max(max(a[j].a1,a[j].a2),max(a[j].a1,a[j].a3));
		}
		cout<<sum<<endl;
	}
	return 0;
}
