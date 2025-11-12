#include<bits/stdc++.h>
using namespace std;
long long sum=0,cnt=0,n,a[100001],maxi;;
bool m(int p,int q){
	maxi=-1;
	sum=0;
	for(int i=q;i<=q+p;i++){
		maxi=max(maxi,a[i]);
		sum+=a[i];
	}
	cout<<maxi<<" "<<sum<<endl;
	if(sum>maxi*2){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(m(i,j)){
				cnt++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<cnt%998244353;
	return 0;
}

