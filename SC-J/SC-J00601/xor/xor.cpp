#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	int m=n;
	int p=1;
	while(1){
		if(p==m)break;
		int sum=0;
		for(int i=p;i<=m;i++){
			sum=sum^a[i];
		}
		if(sum!=k){
			m--;
		}
		else{
			p=m;
			m=n;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}