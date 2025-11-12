#include<bits/stdc++.h>
using namespace std;
long long n,a[10000000],r[10000000],k[10000000];
double ans;
bool cmp(int h,int g){
	return h>g;
}
void xx(int x){
	if(x>=3){
		long long c=0,p=0,h=1;
		for(int j=2;j<x;j++){
			c+=r[j];
		}
		if(c>r[1]){
			ans++;
			for(int q=1;q<x;q++){
				if(r[q]==r[q-1])p++;
			}
			for(int q=2;q<=p+1;q++){
				h*=q;
			}
			ans=ans-(double)h/2+0.5;
		}
		if(x-1==n)return ;
	}
	for(int j=x;j<=n;j++){
		if(!k[j]&&r[x-1]>=a[j]){
			r[x]=a[j];
			k[j]=1;
			xx(x+1);
			k[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		r[1]=a[i];
		k[i]=1;
		xx(2);
	}
	if((int)ans!=ans)ans+=0.5;
	cout<<(int)ans%998244353;
	return 0;
}
