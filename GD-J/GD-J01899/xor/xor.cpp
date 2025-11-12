#include<bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],k,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=b[i-1]^a[i];
	}
	int t=0;
	for(int j=1;j<=n;j++){
		for(int i=t;i<=j;i++){
			if((b[j]^b[i-1])==k){
				t=j+1;
				cnt++;
				break;
			}
		}
		if(t>j) j=t-1;
	}
	cout<<cnt;
	return 0;
}

