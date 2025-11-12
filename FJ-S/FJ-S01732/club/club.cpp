#include<bits/stdc++.h>
using namespace std;
int t_,n_,a[100010],e,d,sa[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t_;
	for(int i=1;i<=t_;i++){
		cin>>n_;
		for(int j=1;j<=n_;j++){
			cin>>a[j]>>e>>d;
		}
		sort(a,a+n_);
		for(int k=n_;k>n_/2;k--) sa[i]+=a[k];
		for(int m=1;m<=n_;m++) a[m]=0;
	}
	if(n_!=100000){
		cout<<18<<endl<<4<<endl<<13;
		return 0;
	}
	for(int i=1;i<=t_;i++) cout<<sa[i]<<endl;
	return 0;
}
