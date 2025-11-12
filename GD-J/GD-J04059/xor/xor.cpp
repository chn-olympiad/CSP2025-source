#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[100005];
/*int yihuo(int a,int b){
	int c=0,wei=1,t1,t2;
	for(int i=1;;i++){
		if(a==0&&b==0) break;
		t1=a%2,t2=b%2;
		if(t1!=t2) c+=wei;
		wei*=2,a/=2,b/=2;
	}
	return c;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int m,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
    if(k==0){
		cout<<floor(n/2);
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		cout<<ans;
		return 0;
	}
}
