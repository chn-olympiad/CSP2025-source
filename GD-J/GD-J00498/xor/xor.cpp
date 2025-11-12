#include<bits/stdc++.h>
using namespace std;
int n,k,sum,a[100005];
long long cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;){
		int j; sum=a[i];
		for(j=i+1;j<n;j++){
			if(sum==k) break;
			sum=sum^a[j];
		}
		if(sum==k){
			i=j;
			cnt++;
		}else i++;
	}
	cout<<cnt<<endl;
	return 0;
}
