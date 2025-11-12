#include<bits/stdc++.h>
using namespace std;

long long f[500005];
long long n,m;
long long a[500005]; 
bool suba=true;
bool subb=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1){
			suba=false;
		}
		if(a[i]!=1&&a[i]!=0){
			subb=false;
		}
	}
	if(suba){
		
		if(m==0){
			if(n%2==0){
				cout<<n/2;
				return 0;
			}
			else{
				cout<<(n-1)/2;
				return 0;
			}
		}
	}
	if(subb){
		if(m==0){
			long long cnt=0,cnt2=0;
			for(int i=1;i<=n;++i){
				if(a[i]==0){
					cnt++;
				}
				if(a[i]==1){
					cnt2++;
				}
			}
			cout<<cnt+cnt2/2;
			return 0;
		}
		else if(m==1){
			long long cnt=0;
			for(int i=1;i<=n;++i){
				if(a[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
			return 0;
		}
	}//救我，就不能出大模拟么 
	//我根本不会位运算 
	else{
		long long cnt=0;
		for(int i=1;i<=n;++i){//起始点 
			for(int j=1;i+j-1<=n;++j){//区间长度 
				long long ans=0;
				for(int m=i;m<=i+j-1;++m){
					ans=(ans^a[m]);
				}
				if(ans==m){
					cnt++;
					i=i+j;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
} 
