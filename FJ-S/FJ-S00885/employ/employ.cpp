#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[15],ans,c[15],f;
string t;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>t;
	f=1;
	for(int i=0;i<t.size();i++){
		if(t[i]=='0'){
			f=0;
			break;
		}
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>c[i];
			a[i]=i;
		}
		do{
			int sum=0,fq=0;
			for(int i=1;i<=n;i++){
				if(t[i-1]=='0'||fq>=c[a[i]]){
					fq++;
				}else{
					sum++;
				}
			}
			if(sum>=m){
				ans++;
			} 
		}while(next_permutation(a+1,a+n+1));
	}else{
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		if(m==n){
			ans=f;
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					ans=0;
					break;
				}
				ans*=i;
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
} 
