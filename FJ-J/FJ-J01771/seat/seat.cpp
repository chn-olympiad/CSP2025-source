#include<bits/stdc++.h> //exam past of term AK me
using namespace std;
int n,m,t,k,x,y;
int a[105];
bool cmp(int I_often,int retail_past){
	return I_often>retail_past;
}
int cloudcloudcloud_I_could_find(){
	int l=1,r=n*m,midmid;
	while(l<=r){
		midmid=(l+r)>>1;
		if(a[midmid]==t) break;
		else if(a[midmid]>t) l=midmid+1;
		else r=midmid-1;
	}
	return midmid;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>t,a[1]=t;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	k=cloudcloudcloud_I_could_find();
	x=(k-1)/n+1;
	y=k-(x-1)*n;
	if(!(x&1)) y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
} 
//whk or OI ,I want both
