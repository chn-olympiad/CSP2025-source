#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],q[5005],h[5005],s,e;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
   	cin>>n;
   	for(int i=1;i<=n;i++){
   		cin>>a[i];
   		s+=a[i];
	}
	sort(a+1,a+n+1,cmp);
	q[1]=a[1];
	h[1]=a[n];
	for(int i=2;i<=n;i++){
		q[i]=q[i-1]+a[i];
		h[i]=h[i-1]+a[n-i+1];
	}
	int m=n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			int ma=a[i+1],w=s-q[i]-h[j];
			if(w>2*ma&&n-i-j>=3) e++;
			int z=w-2*ma;
			for(int k=i+1;k<=n-j-1;k++){
				if(a[k]<z&&n-i-j-1>=3) e++;
			}
		}
	}
	e=e%998;
	e=e%244;
	e=e%353; 
	cout<<e;
    return 0;
}
