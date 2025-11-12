#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n,k,ans;
cin>>n>>k;
int a[500001];
for(int i = 1;i<=n;i++){
	cin>>a[i];
}
if(k==1){
for(int i = 1;i<=n;i++){
	if(a[i]==1)ans++;
}
cout<<ans;
}else if(k==0){
	for(int i = 1;i<=n;i++){
	if(a[i]==0)ans++;
	else if(a[i]==1&&a[i+1]==1){
		ans++;
		i++;
	}
}
cout<<ans;
}

return 0;
}
