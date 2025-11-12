#include<bits/stdc++.h>
using namespace std;
int gon[5105]={0},sum[5105]={0},n,ans;long long rmmr[5010];
long long jc(int i){
	if(rmmr[i]){
		return rmmr[i];
	}
	return rmmr[i]=(jc(i-1)*i)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	rmmr[1]=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gon[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			if(gon[j]>gon[j-1]){
				swap(gon[j],gon[j-1]);
			}
		}
	}
	sum[1]=gon[1];sum[0]=0;
	for(int i=2;i<=n;i++){
		sum[i]+=sum[i-1]+gon[i];
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			if((sum[j]-sum[i])>gon[i]){
				ans+=jc(n-j);
				ans%=998244353;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
