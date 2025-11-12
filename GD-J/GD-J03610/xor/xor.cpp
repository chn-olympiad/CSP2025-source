#include<bits/stdc++.h>
using namespace std;
int n,k,sum[500010][21],cnt,w;
int a[500010];
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int s=a[i];
		for(int j=1;j<=200;j++){
			if(s&1){
				sum[i][j]=sum[i-1][j]+1;
			}
			s>>=1;
			if(s<=0)break;
		}
		if(a[i]!=1)f=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	if(k==0&&f==0){
		cout<<n/2;
		return 0;
	}
	int ka=k;
	while(ka>0){
		ka>>=1;
		w++;
	}
	int l=1,r=1;
	while(l>=r&&r<=n){
		for(int i=0;i<=r-l;i++){
			int f=0;
			for(int j=1;j<=21;j++){
				if((sum[r][j]-sum[l+i-1][j])%2!=(k>>(j-1))%2){
					f=1;
					break;
				}
			}
			if(f==0){
				cnt++;
				l=r+1;
				break;
			}
		}
		r++;
	}
	cout<<cnt;
}
