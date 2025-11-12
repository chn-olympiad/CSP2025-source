#include<bits/stdc++.h>
using namespace std;
int n,sum;
struct r{
	int aa,bb,cc;
}a[100005];
bool cmp(r x,r y){
	return x.aa-(max(x.bb,x.cc))>y.aa-max(y.bb,y.cc);
}
bool cmp2(r x,r y){
	return x.bb-x.cc>y.bb-y.cc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int T;
cin>>T;
while(T--){
	sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
		scanf("%d %d %d",&a[i].aa,&a[i].bb,&a[i].cc);
	int a1=n/2,b1=n/2,c1=n/2;
	sort(a+1,a+1+n,cmp);
	int i=1;
	for(i=1;a1>0 && a[i].aa-max(a[i].bb,a[i].cc)>=0;i++){
		sum+=a[i].aa;
		a[i].aa=0,a[i].bb=0,a[i].cc=0;
		a1--;
	}
	sort(a+i,a+1+n,cmp2);
	for(i;b1>0 && a[i].bb-a[i].cc>=0;i++){
		sum+=a[i].bb;
		a[i].aa=0,a[i].bb=0,a[i].cc=0;
		b1--;
	}
	for(i;i<=n;i++){
		sum+=a[i].cc;
	}
	cout<<sum<<'\n';
}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
