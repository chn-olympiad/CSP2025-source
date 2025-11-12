#include<iostream>
using namespace std;
long long n,k,a[500005],cnt,x[500005];
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		x[i]=x[i-1]^a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	if(flag&&k==0){
		cout<<n/2;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if((x[j]^x[i-1])==k){
				cnt++;
				i=j+1;
				break;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
