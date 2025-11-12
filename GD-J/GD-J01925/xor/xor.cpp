#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,k,a[maxn],cnt,sum,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i+=c){
		sum=a[i],c=1;
		if(sum==k){
			cnt++,i++,c=0;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				cnt++;
				i=j+1,c=0;
				break;
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
