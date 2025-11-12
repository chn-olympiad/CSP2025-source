#include<bits/stdc++.h>
#define int long long
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=5e5+30;
int n,k;
int a[N];
bool b[30][N];
bool has[30][N]={};
bool f[30]={},yk[30]={};
signed main(){
	file(xor);
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	cin>>n>>k;
	bool all1=1,all10=1;
	for(int i=20;i>=0;i--){
		yk[i]=(k>>i)&1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) all1=0;
		if(a[i]!=1 && a[i]!=0)all10=0;
		for(int j=20;j>=0;j--){
			b[j][i]=(a[i]>>j)&1;
		}
	}
	if(all1==1){
		if(k==1) cout<<n<<endl;
		else if(k==0) cout<<n/2<<endl;
		else cout<<0<<endl;
		return 0;
	}
	else if(all10==1){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
			cout<<sum<<endl;
			return 0;
		}
		else if(k==0){
			int lst=a[1],sum=0,lon=1; 
			for(int i=2;i<=n;i++){
				if(lst==a[i]) lon++;
				else {
					if(lst==1) sum+=lon/2;
					else sum+=lon;
				}
			} 
			cout<<sum<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	else if(n<=1000){
		int s[N];
		for(int i=1;i<=n;i++){
			s[N]=s[N-1]^a[i];
		}
		
	}
	for(int i=0;i<=20;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=b[i][j-1]^b[i][j];
		}
	}
//	for(int i=0;i<=1;i++){
//		for(int j=0;j<=n;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int res=0;
	for(int i=1;i<=n;i++){
		bool is_ok=1;
		for(int j=0;j<=20;j++){
			if(yk[j]!=(f[j]^b[j][i]) && has[j][i]==0){
				is_ok=0;
				break;
			}   
		}
		if(is_ok==1){
			res++;
			for(int j=0;j<=20;j++){
				if((b[j][i]^f[j])==1) f[j]=!f[j];
				has[j][i]=0;
			}
		}
		else{
			for(int j=0;j<=20;j++){
				has[j][i]=has[j][i-1]|(b[j][i]^f[j]);
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
/*
4 3
2 1 0 3
*/
