#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,num,cnt;
int a[N],b[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])num++;
		else cnt++;
	}
	if(k==0){
		cout<<max(num/2,cnt/2);
	}
	if(k==1){
		cout<<num;
	}
	return 0;
}
