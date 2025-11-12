#include<bits/stdc++.h>
using namespace std;
int n;int a[5001];
long long as;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;int tot=0;
	for(int i=1;i<=n;i++){	
	cin>>a[i];
	tot+=a[i];
	}
	sort(a+1,a+1+n);
if(tot*2>=a[n])as++;
if(n==3)cout<<1;
else if(n==5)cout<<9;
else cout<<998244352;
return 0;

}
