#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int num,ans=0;
	bool fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!fl){
			num=a[i];
			fl=1;
		}
		else num=(num xor a[i]);
		if(num==k){
			ans+=1;
			fl=0;
		}
	}
	cout<<ans;
	return 0;
}