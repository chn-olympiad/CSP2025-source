#include<iostream>
using namespace std;
long long n,k,a[500005],ans,cnt;
bool f=false,ff=false;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=true;
		if(a[i]!=0&&a[i]!=1)ff=true;
	}
	if(f==false){
		cout<<n/2;
		return 0;
	}
	if(ff==false){
		if(k==0){
			long long ans=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else{
					cnt=0;
					while(a[i]==1){
						cnt++;
						i++;
					}
					ans+=cnt/2;
				}
			}
			cout<<ans;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=i;j<=n;j++){
			ans^=a[j];
			if(ans==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
