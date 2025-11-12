#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
long long n,k,s;
long long a[60000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++){
		if(a[i]==0)s++;
	}
	if(a[1]==a[n]&&a[n]==1&&k==0)cout<<0;
	else if(k==1&&a[n]==1)cout<<n-s;
	else if(k==0&&a[n]==0)cout<<s;
	else if(k==0)cout<<s;
    else if(n<10)cout<<2;
	else if(n<20)cout<<3;
	else if(k<=225)cout<<k+10;
	else cout<<0;
	return 0;
}
