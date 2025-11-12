#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[10000000];
int n,ans=0;
void as(int cnt,int num,bool id,int s){
	if(id){
		s+=a[cnt];
	}
	if(num==0||cnt==n){
		if(num!=0){
			return ;
		}
		if(s>a[cnt]*2){
			
			ans=(ans+1)%998244353;
		}
		return ;
	}
	as(cnt+1,num,false,s);
	as(cnt+1,num-1,true,s);
}
signed main(){
	bool id=true;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			id=false;
		}
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		as(1,i-1,true,0);
		as(1,i,false,0);
		
	}
	cout<<ans;
}
