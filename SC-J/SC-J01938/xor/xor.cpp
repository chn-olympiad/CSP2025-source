#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
long long n,k,a[500005],ans;
long long b[10000005],c[10000005],d[10000005];
long long yh(long long x,long long y){
	int jb1=0,jb2=0,t=0,t1=0;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	while(x||y){
		if(x){
			b[++jb1]=x%2;
			x/=2;
		}
		if(y){
			c[++jb2]=y%2;
			y/=2;
		}
	}
	if(jb1==0)jb1=1;
	if(jb2==0)jb2=1;
//	cout<<" b=";
//	for(int i=1;i<=jb1;i++)cout<<b[i]<<" ";
//	cout<<"c=";
//	for(int i=1;i<=jb2;i++)cout<<c[i]<<" ";
	t=max(jb1,jb2);
	for(int i=1;i<=t;i++)if(b[i]!=c[i])d[i]=1;
//	cout<<"d=";
//	for(int i=1;i<=t;i++)cout<<d[i]<<" ";
	for(int i=1;i<=t;i++){
		t1+=pow(2,i-1)*d[i];
//		cout<<" t1="<<t1<<" ";
	}
	return t1;
}
long long f(long long jb,long long x){
	if(jb==n+1)return ans=max(ans,x);
	int sum=0;
	for(int i=jb;i<=n;i++){
//		cout<<" jb="<<jb<<" i="<<i<<" sum="<<sum<<" a[i]="<<a[i];
		sum=yh(sum,a[i]);
//		cout<<" sum1="<<sum<<endl;
		if(sum==k){
			return f(i+1,x+1);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,0);
	cout<<ans;
//	cout<<"\nYh="<<yh(2,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}