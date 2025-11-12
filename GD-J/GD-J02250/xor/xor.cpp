#include<bits/stdc++.h>
using namespace std;
int sum[500105],a,n,k,js=0,ans=0;
struct d{
	int l,r;
};
queue<d> b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;sum[i]=a^sum[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if((sum[i]^sum[j])==k) b.push({j+1,i});
		}
		if(sum[i]==k) b.push({1,i});
	}
	while(!b.empty()){
		if(b.front().l>js){
			js=b.front().r;
			++ans;
		}
		b.pop();
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
