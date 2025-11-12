#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long int n,m,cun,cnt,ans,mc = 1;
cin>>n>>m;
long long int a[111];
for(int i = 1;i<=n*m;i++){
	cin>>a[i];
}
cun = a[1];
sort(a+1,a+1+n*m);
for(int i = n*m;i>=1;i--){
	if(cun==a[i]){
	cnt = mc;	
	break;	
	}
	mc++;
}
ans = cnt/m;
if(cnt%m==0){
	if(ans%2==0){
		cout<<ans<<' '<<1;
	}else if(ans%2==1){
		cout<<ans<<' '<<m;
	}
}else if(cnt%m!=0){
	if((ans+1)%2==0){
		cout<<ans+1<<' '<<(m+1)-cnt%m;
	}else if((ans+1)%2==1){
		cout<<ans+1<<' '<<cnt%m;
	}
}
return 0;
}
