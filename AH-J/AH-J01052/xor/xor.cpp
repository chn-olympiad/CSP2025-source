#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		b[i]=b[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int yh=b[i-1]^b[j];
			if(yh==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
