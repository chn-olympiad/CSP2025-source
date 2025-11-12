#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,a[maxn],ans;
void f(int x,long long p,int k){
	if(x>n)return ;
	if(k>=2&&p>a[x+1])ans++;
	f(x+1,p+a[x+1],k+1);
	f(x+1,p,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=1e9;
	sort(a+1,a+1+n);
	f(1,0,0);
	f(1,a[1],1);
	cout<<ans;
    return 0;
}
