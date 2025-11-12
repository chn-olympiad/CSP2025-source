#include<bits/stdc++.h>
using namespace std;
int t,n;
long long b[3];
struct p{
	long long s1,s2,s3,zd,zx,zj;
}a[100010];
bool cmp(p a,p b){
	if(a.zd!=b.zd){
	return a.zd>b.zd;
}else{
		return a.zx>  b.zx;
}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--){
	cin>>n; 
	long long sum=0;
	b[1]=1;
	b[2]=1;
	b[3]=1;
	for(int i=0;i<n;i++){
		a[i].s1=0;a[i].s2=0;a[i].s3=0;
		a[i].zj=0;
		a[i].zd=0;
		a[i].zx=0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2>>a[i].s3;
		a[i].zj=a[i].s1+a[i].s2+a[i].s3;
		long long h=max(a[i].s1,a[i].s2),m=min(a[i].s1,a[i].s2);
		a[i].zd=max(h,a[i].s3);
		a[i].zx=min(m,a[i].s3);
		a[i].zj=a[i].zj-a[i].zd-a[i].zx;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(n==2){
			if(i==1){
				sum+=a[i].zd;
				continue;
			}
			sum+=a[i].zj;
			continue;
		}else
		if(a[i].zd==a[i].s1&&b[1]<=n/2){
		b[1]++;
		sum+=a[i].zd;
		}else 
		if(a[i].zd==a[i].s2&&b[2]<=n/2){
		b[2]++;
		sum+=a[i].zd;
		}else
		if(a[i].zd==a[i].s3&&b[3]<=n/2){
		b[3]++;
		sum+=a[i].zd;
		}else 
		//最大 
		if(a[i].zj==a[i].s1&&b[1]<=(n/2)-1){
		b[1]++;
		sum+=a[i].zj;
		}else 
		if(a[i].zj==a[i].s2&&b[2]<=(n/2)-1){
		b[2]++;
		sum+=a[i].zj;
		}else
		if(a[i].zj==a[i].s3&&b[3]<=(n/2)-1){
		b[3]++;
		sum+=a[i].zj;
		}else
		//中间	
		if(a[i].zx==a[i].s1&&b[1]<=(n/2)-1){
		b[1]++;
		sum+=a[i].zx;
		}else 
		if(a[i].zx==a[i].s2&&b[2]<=(n/2)-1){
		b[2]++;
		sum+=a[i].zx;
		}else
		if(a[i].zx==a[i].s3&&b[3]<=(n/2)-1){
		b[3]++;
		sum+=a[i].zx;
		}
		//最小	
	}
    cout<<sum<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0; 
}
