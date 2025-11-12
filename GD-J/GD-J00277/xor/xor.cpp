#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
int n,a[N],ans;
int k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=-1;
	for(int i=1;i<=n;i++){
		if(cnt==-1)cnt=a[i];
		else cnt^=a[i];
		if(cnt==k){
			ans++;
			cnt=-1;
		}
	}cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
} 
