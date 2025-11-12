#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1005];
ll n,m;
ll xr;
ll xxr;
ll d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
	d=n*m;
    for(int i=1;i<=d;i++){
    	scanf("%lld",&a[i]);
	}
	xr=a[1];
	stable_sort(a+1,a+d+1,greater<ll>());
	for(int i=1;i<=d;i++){
		if(a[i]==xr){
			xxr=i;
		}
	}
	if(xxr>m&&xxr%m!=0){
		if(((xxr/m)+1)%2!=0){
			cout<<(xxr/m)+1<<' '<<xxr%m<<endl;
		}else{
			cout<<(xxr/m)+1<<' '<<m-(xxr%m)+1<<endl;
		}
	}else{
		if(xxr>m&&xxr%m==0){
			if((xxr/m)%2!=0){
				cout<<xxr/m<<' '<<1<<endl;
			}else{
				cout<<xxr/m<<' '<<m<<endl;
			}
		}else{
			cout<<1<<' '<<xxr<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
