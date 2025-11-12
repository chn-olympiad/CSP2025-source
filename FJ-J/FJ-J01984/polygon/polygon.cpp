#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
inline int read(){
	int x=0;
	char ch=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
bool p(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=read();
	int a[5001];
	a[0]=0;
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,p);
//	for(int i=2;i<=n;i++)a[i]+=a[i-1];
	long long s=0;
//	for(int i=1;i<=n-2;i++){
//		for(int j=i+2;j<=n;j++){
//			if(2*(a[i]-a[i-1])<a[j]-a[i-1]){
//				for(int k=i;k<=j;k++)cout<<a[k]-a[k-1]<<" ";
////				cout<<" "<<a[i]-a[i-1]<<" "<<a[j]-a[i-1];
//				cout<<"\n";
//				long long x=1;
//				for(int k=j+1;k<=n;k++)x=(x<<1)%MOD;
//				s=(s+x)%MOD;
//				break;
//			}
//		}
//	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(a[i]<a[j]+a[k]){
					long long x=1;
					for(int l=k+1;l<=n;k++)x=(x<<1)%MOD;
					s=(s+x)%MOD;
				}
			}
		}
	}
	cout<<s;
	return 0;
}
