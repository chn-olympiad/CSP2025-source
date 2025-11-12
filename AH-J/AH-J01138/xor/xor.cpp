#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,sum=0;
ll a[100100];
struct stu{
	ll r,l;
}aa[100010];
bool pd(ll x,ll y){
	ll s[10000],rx=0,ry=0;
	ll t=1;
	while(x!=0){	
		s[t]=x%2;
		x=x/2;
		t++;
	}	
	for(int i=t;i>=1;i--){
		rx=rx*10+s[i];
		
	}
	t=1;
	while(y!=0){	
		s[t]=y%2;
		y=y/2;
		t++;
	}	
	for(int i=t;i>=1;i--){
		ry=ry*10+s[i];
	}
	ll f=0;
	if(x>y){
		while(x!=0){
			if(x%10==y%10){
				f=f*10+1;
			}
			x=x/10;
			y=y/10;
		}
		cout<<f<<endl;
		if(f==k) return true;
		else return false;
	}
	if(x<y){
		while(y!=0){
			if(y%10==x%10){
				f=f*10+1;
			}
			y=y/10;
			x=y/10;
		}
		cout<<f<<endl;
		if(f==k) return true;
		else return false;
	}
}
bool cmp( const stu &x, const stu &y){
	return x.r<y.r;
}
int main(){
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	cout<<pd(1,2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool f=0;
			for(int t=i;t<=j;t++){
				if(!pd(a[t],a[t+1])){
					f=1;
				}	
			}
			if(f==0){
				aa[sum].l=i;
				aa[sum].r=j;
			}
		}
	}
	sort(aa+1,aa+sum+1,cmp);
	ll ant=1,R=aa[1].r;
	for(int i=2;i<=sum;i++){
		if(aa[i].l>R){
			ant++;
			R=aa[i].r;
		}
	}
	//cout<<ant;
	return 0;
}
