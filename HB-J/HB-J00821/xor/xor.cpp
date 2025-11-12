#include <bits/stdc++.h>
/*#Shang4Shan3Ruo6Shui4*/
using namespace std;
const int MAXN=5e5+5;
long long n,k,a[MAXN],sum[MAXN],ans=-0x3f3f3f3f,book[MAXN];
int check(long long num){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==num){
			cnt++;
			book[i]=1;
		}
	}
	int op;
	for(int kl=1;kl<=n;kl++){
		for(int kr=kl+1;kr<=n;kr++){
			op=0;
			for(int i=kl;i<=kr;i++){
				if(book[i]==1){
					op=1;
				}
			}
			if(op==0){
				if((sum[kr]^sum[kl-1])==num){
					cnt++;
					for(int i=kl;i<=kr;i++){
						book[i]=1;
					}
					
				}
			}
		}
	}
	return cnt;
}	
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(a[i]^sum[i-1]);
	}
	memset(book,0,sizeof(book));
	cout<<check(k);
	return 0;
}
