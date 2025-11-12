#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],num,ans,c,r;
bool cmp(long long xx,long long yy){
    return xx>yy;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
	    if(a[i]==num){
	    	ans=i;
	    	break;
		}
	}
	//for(int i=1;i<=n*m;i++){
	//    cout<<a[i]<<endl;
	//}
	//cout<<"ans"<<ans<<' ';
	r=ans/n;
	if(ans%n!=0){
		r++;
		if(r%2==0){
		c=n-ans%n+1;
	    }else{
		c=ans%n;
		}
	}else{
		if(r%2==0){
			c=1;
		}else{
			c=n;
		}
	}

	cout<<r<<' '<<c;
	return 0;
}
