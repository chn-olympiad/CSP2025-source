#include<bits/stdc++.h>
using namespace std;
const int N=1e7+6;
int n,a[N],s[N],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2){
		cout<<0<<endl;
	} else if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
