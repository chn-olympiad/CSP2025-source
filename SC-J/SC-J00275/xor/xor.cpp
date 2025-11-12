#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int cnt;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	int no=a[1];
	int ans=0;
	if(k==1){
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;){
		if(a[i]==0){
			ans++;
			i++;
		}
		else if(a[i]==1&&a[i+1]==1){
			i+=2;
			ans++;
		}else{
			i++;
		}
	}
	cout<<ans;
	return 0;
} 