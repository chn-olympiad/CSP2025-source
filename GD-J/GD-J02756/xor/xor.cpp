#include <bits/stdc++.h>
using namespace std;
int a[500001];
long long sum[500001];
bool fs[500001],fe[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int st=0;
	for(int i=1;i<=n;i++){
		if(sum[i]==k){
			cnt++;
			fs[st]=1;
			fe[i]=1;
			st=i+1;
			for(int j=i+1;j<=n;j++){
				sum[j]^=sum[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		int kk=0;
		for(int j=i+1;j<=n;j++){
			sum[j]^=kk;
			if((sum[i]^sum[j]==k)&&(!fs[i])&&(!fe[j])){
				cnt++;
				kk=sum[j];
			}
		}
	}
	cout<<cnt;
	return 0;
} 
