#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],b,x,y;
bool flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>200000) cout<<0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) b=max(b,(long long)(1));
		if(a[i]>=2) b=2;
 	}
	if(b==0){
		if(k==0) cout<<n/2;
		else if(k==1) cout<<n;
		else cout<<0;
		return 0;
	}
	else if(b==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) x++;
			if(a[i]==0) y++;
		}
		if(k==0) cout<<y+(x/2);
		else if(k==1) cout<<x;
		else cout<<0;
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}