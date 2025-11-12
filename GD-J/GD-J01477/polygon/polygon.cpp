#include<bits/stdc++.h>
using namespace std;
int sum[134216728];
int main(){
	freopen("polyon.in","r",stdin);
	freopen("polyon.out","w",stdout);
	int n,a[5010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[int(pow(2,i-1))]=a[i];
	}
	for(int i=1;i<pow(2,n);i++){
		if(sum[i]==0){
			int ii=i;
			for(int j=1;ii;j++){
				if(ii&1==1) sum[i]+=sum[int(pow(2,j-1))];
				ii/=2;
			} 
		}
		cout<<sum[i]<<' ';
	}
	long long cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=pow(2,n+1-i);j<pow(2,n);j+=pow(2,i)){
			if(sum[j]>a[i]){
				cnt++;
				cout<<i<<' '<<j<<'\n';
			}
		}
	}
	cout<<cnt;
	return 0;
}
