#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int c[n+2];
	for(int i=1;i<=n;i++){
		c[i]=0;
	}
	int s=0;
	int g=pow(2,n);
	for(int i=1;i<=g;i++){
		int maxn=0,h=0;
		for(int i=1;i<=n;i++){
			if(c[i]==1){
				h+=a[i];
				if(a[i]>=maxn)maxn=a[i];
			}
		}
		if(h>2*maxn)s++;
		s=s%998244353;
		int f=1;
		for(int i=n;i>=1;i--){
			c[i]+=f;
			f=0;
			if(c[i]>1)c[i]=0,f=1;
		}
	}
	cout<<s;
 return 0;
}
