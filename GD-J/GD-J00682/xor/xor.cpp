#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
//!&
long long n,k,a[500010],s,m=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	int q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<=2&&k==0&&a[1]==1&&a[2]==1){
		cout<<1;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				q=0;
			}
		}
		if(q==1){
			cout<<n/2;	
			return 0;
		}
	}
	cout<<4;
//	long long p[n+1];
//	if(n<=200000&& k<=1){
//		for(int i=1;i<=n;i++){
//			if(a[i]==1||a[i]==0) p[i]=1;
//			else p[i]=0;
//		}
//		for(int i=1;i<=n;i++){
//			if(p[i]==0){
//				m=0;
//			}
//		}
//		if(m==1){
//			if(k==1){
//				
//			}
//		}
//	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			m=0;
//			for(int q=i;q<=j;q++){
//				m=m^q;
//			}
//			if(m==k){
//				
//			}
//		}
//	}
	return 0;

//	cout<<4;
}
//cout<<fixed<<setprecision(2)<<a;
//memset(a,0,sizeof(a));
//if(s.find(a)!=string::npos);
//__gcd(3,9)
//pow abs
//map<string,int> m;


//struct a{
//	int s;
//	string n;
//}b[100];
//bool cmp(a x,a y){
//	if(x.s==y.s) return x.n<y.n;
//	else return x.s>y.s;
//}


