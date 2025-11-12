#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N],d[N];
int k;
long long m4;
void f(int x,int y,int z){
	if(x>=y&&x>=z){
		if(y>=z){
			d[k]=x-y;
		}else{
			d[k]=x-z;
		}
		k++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,k1=0,k2=0,k3=0;
		k=0;
		long long m1=0,m2=0,m3=0;
		m4=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i]){
				m1+=a[i];
				k1++;
			}else if(b[i]>=c[i]){
				m2+=b[i];
				k2++;
			}else{
				m3+=c[i];
				k3++;
			}
		}
		if(k1>n/2){
			for(int i=0;i<n;i++){
				f(a[i],b[i],c[i]);
			}
		}else if(k2>n/2){
			for(int i=0;i<n;i++){
				f(b[i],a[i],c[i]);
			}
		}else if(k3>n/2){
			for(int i=0;i<n;i++){
				f(c[i],b[i],a[i]);
			}
		}
		sort(d,d+k);
		for(int i=0;i<k-n/2;i++){
			m4+=d[i];
		}
		cout<<m1+m2+m3-m4<<endl;
	}
	return 0;
}
