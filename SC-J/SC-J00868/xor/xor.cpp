#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],res;
void d(int l,int ans){
	int s=0;
	if(l==n){res=max(ans,res);return;}
	for(int i=l;i<=n;i++){
		for(int j=i;j<=n;j++){
			int l1=i;
			int r1=j;
			for(int p=l1;p<=r1;p++)s^=a[p];
			if(s==k){++ans;d(r1,ans);}
			s=0;
			ans--;
		}
		
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		d(i,0);
	}
	cout<<res;
	return 0;
}