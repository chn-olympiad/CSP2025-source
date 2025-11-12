#include<bits/stdc++.h>
using namespace std;
long long n,m,c[550],a[550],sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int f=1;
	a[0]=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==0){
			f=0;
			a[i+1]+=1;
		} 
	}
	if(((m<=n&&n<=100)||(m<=n&&n<=500))&&(f==1)){
		long long s1=n;
		for(int i=1;i<=m-1;i++){
			s1*=(n-i);
		}
		cout<<s1%998244353;
		return 0;
	}
	if(m==n){
		sort(c+1,c+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]>=c[i]){
				cout<<0;
				return 0;
			}
			long long B=0,A=0;
			for(int j=n;j>i;j++){
				if(c[i]>a[j]){
					long long cnt=j-i+1;
					for(int z=1;z<=j-i;z++){
						cnt*=(j-i+1-z);
					}
					sum+=cnt-1;
					A=j;
					B=1;
					break;
				}
			}
			if(B==1)i=A;
		}
		cout<<sum%998244353;
		return 0;
	}
	return 0;
} 
