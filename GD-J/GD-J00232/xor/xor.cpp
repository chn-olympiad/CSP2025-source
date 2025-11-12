#include<iostream>
using namespace std;
int n,k,a[500001],cnt,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		for(int j=cnt+1;j<=i;j++){
			int b=a[i]^a[j-1];
			if(b==k){
				ans++;
				cnt=i;
				a[i]=0;
				break;
			}
		}
	}
	cout<<ans;
}
