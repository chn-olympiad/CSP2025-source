#include<bits/stdc++.h>
using namespace std;
long long n,m=0,k,s=0,ans=0,a[500005],arr[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	arr[0]=0;
	for(int i=1;i<=n;i++){
		s^=a[i];
		arr[i]=s;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j<i;j++){
			if((arr[i]^arr[j])==k){
				ans++;
				m=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
