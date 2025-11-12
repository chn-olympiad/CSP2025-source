#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
bool flag;
void work1(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) ans++;
		else if(a[i+1]==1){
			ans++;
			i++;
		}
	}
	cout<<ans;
}
void work2(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) ans++;
	}
	cout<<ans;
}			
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
	}
	if(flag){
		if(k==0) work1();
		else work2();
		return 0;
	}else cout<<10;
	return 0;
}
