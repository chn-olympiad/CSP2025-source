#include<iostream>
using namespace std;
int n,k,cnt,ans,res,a[500005],l[500005],r[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k){
					cnt++;
					l[cnt]=i;
					r[cnt]=j;
				}
			}else{
				sum^=a[j];
				if(sum==k){
					cnt++;
					l[cnt]=i;
					r[cnt]=j;
				}
			}
		}
	}
	//cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++){
		res=1;
		int lr=r[i];
		for(int j=i+1;j<=cnt;j++){
			if(lr<l[j]){
				res++;
				lr=r[j];
				//cout<<l[i]<<' '<<r[i]<<' '<<l[j]<<' '<<r[j]<<'\n';
			}
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}