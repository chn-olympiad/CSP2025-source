#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,mx3=0;
int a[N],mn;
long long ans=0,k=1;
int st(int x,int y){
	k=1;
	for(int i=x-y+1;i<=x;i++){
		if(!(i<=y)){
			k*=i;
			k=k%998244353;
		}
	}
	if(y<x-y+1){
		mn=y;
	}else{
		mn=x-y;
	}
	for(int i=mn;i>=1;i--){
		k/=i;
		
	}
	return k;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx3=max(mx3,a[i]);
		if(n==3){
			ans+=a[i];
		}
	}
	if(n==3){
		if(ans>mx3*2){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		} 
	}else{
		if(n>=4){
			for(int i=3;i<=n;i++){
				ans+=st(n,i);
			}
			cout<<ans<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
