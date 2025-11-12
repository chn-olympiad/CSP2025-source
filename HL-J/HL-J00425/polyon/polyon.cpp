#include<bits/stdc++.h>
using namespace std;
i64 Mod=998244353,r,a[501],d[5002],pan[3];
int main() {
	freopen("polyon.in","r",stdin);
	freopen("polyon.out","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=0;i<3;i++)cin>>pan[i];
		sort(pan,pan+3);
		if((pan[0]+pan[1]>pam[2])&&(pan[2]-pan[0]<pan[1])&&(pan[2]-pan[1]<pan[0])){
			cout<<1;
		}else{
			cout<<0;

			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}
	}
	return 0;
}

