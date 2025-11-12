#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
	 	if(a[i]==k){
	 		ans++;
		}else if(a[i]^a[i+1]==k){
			ans++;
			i++;
		}else if(a[i]^a[i+1]^a[i+2]==k){
			ans++;
			i+=2;
		}
	}
	 cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
