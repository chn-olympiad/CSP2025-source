#include <bits/stdc++.h>
using namespace std;
int n,k,cnt=0;
int a[100005],b[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt1=a[i],j=i+1;
		if(i==k){
			cnt++;
		}
		for(;j<=n;j++){
			cnt1=(cnt1 xor a[j]);
//			cout<<i<<" "<<j<<endl;
			if(cnt1==k){
				cout<<i<<" "<<j<<endl;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<" "<<(2 xor 1);
	return 0;
}
