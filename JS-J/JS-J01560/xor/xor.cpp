#include<bits/stdc++.h>
using namespace std;
int n,ans,k,a[10005],b=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;
			b=-1;
		}
		else{
			if(b==-1)b=a[i];
			else b=(b^a[i]);
			if(b==k){
				ans++;
				b=-1;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}
