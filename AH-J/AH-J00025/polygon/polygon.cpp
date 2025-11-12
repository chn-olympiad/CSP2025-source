#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	if(n<=3){
		if(n<3) cout<<0;
		else {
			int d=max(a[1],max(a[2],a[3]));
			if(b[3]>2*d) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
