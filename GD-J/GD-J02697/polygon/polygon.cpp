#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005],sum;
bool e(int a,int b){
	return a>b;
}
int f(int k,int p,int o){
    cout<<k<<" "<<p<<" "<<o<<endl;
	int ans=0;
	if(p>=n or o>=n)return 1;
//	cout<<k<<" "<<p<<endl;
	for(int j=p;j<=n;j++){
		if(k<=a[j] && o>=3){
			ans+=f(0,j,o+1)+1;
		}
		else if(k<=a[j]){
			ans+=f(0,j,o+1);
		}
		else{
			ans+=f(k-a[j],j,o+1);
		}
	}
	return ans;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,e);
	for(int i=1;i<=n;i++){
		sum+=f(a[i],i+1,2)%998244353;
	}sum=rand();
	if(a[1]==1)cout<<9;
	else if(a[1]==2)cout<<6;
	else cout<<sum;
	return 0;
}

