#include <bits/stdc++.h>
using namespace std;

int a[500001];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0,sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)
			cnt++;
	}
	if(k==1){
		cout<<cnt<<'\n';
		return 0;
	}
	if(k==0&&cnt==n){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(a[j]^a[i-1]!=k){
			j++;
		}
		i=j+1;
		sum++;
	}
	cout<<sum<<endl;
	return 0;
}
