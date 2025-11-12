#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
int tot;

int check(int x,int y){
	ans=x;
	if(x==y){
		if(a[x]==k){
			tot++;
			return x;
		}
	}
	for(int i=x;i<=y;i++){
		ans=ans^a[i];
		if(ans==k){
			tot++;
			return i;
		}
	}
	return n;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int r = check(i,n);
		int x=r+1;
		while(r!=n){
			r = check(x,n);
			x=r+1;
		}
	}
	cout<<tot;
	return 0;
}
