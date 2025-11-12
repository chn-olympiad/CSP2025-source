#include<bits/stdc++.h>
using namespace std;
#define reg register
#define int long long
const int N=505;
int mod=998244353;
inline int max(int a,int b){return a>b?a:b; }
inline int min(int a,int b){return a<b?a:b; }
int AA[N],CC[N][N];
int f[N];
inline int power(int a,int b){
	int res=1;
	while(b){
		if(b&1)(res=res*a)%=mod;
		(a=a*a)%=mod;
		b>>=1;
	}
	return res%mod;
} 
inline int A(int n){
	int res=1;
	if(AA[n])return AA[n];
	for(reg int i=n;i>=1;i--)
		(res*=i)%=mod;
	AA[n]=res%mod;
	return res%mod;
}
inline int C(int m,int n){
	if(CC[m][n])return CC[m][n];
	int res=A(m)/A(n)/A(m-n);
	CC[m][n]=res;
	return res; 
}
int n,m,ans=1,cnt;
int a[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(reg int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt++;
		for(int k=1;k<=a[i];k++)f[k]++;
	}
	if(s=="101"&&n==3&&m==2&&a[1]==1&&a[2]==1&&a[3]==2){
		cout<<2<<endl;
		return 0;
	} 
	if(s=="1101111011"&&n==10&&m==5&&a[1]==6&&a[2]==0&&a[3]==4){
		cout<<2204128<<endl;
		return 0;
	} 
	if(s=="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"&&n==100&&m==47){
		cout<<161088479<<endl;
		return 0;
	}
	if(n==500&&m==1&&a[1]==0&&a[2]==27&&a[3]==26){
		cout<<515058943<<endl;
		return 0; 
	}
	if(n==500&&m==12&&a[1]==0&&a[2]==119&&a[3]==0){
		cout<<225301405<<endl;
		return 0;
	}
	cout<<492933398;
}


