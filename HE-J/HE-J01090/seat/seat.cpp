#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120];
int l;
int ans;
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
		if(i==1||a[i]>a[1]){
			ans++;
		}
	}
	//cout<<ans<<endl;
	if(ans%n==0){
		c=ans/n;
	}
	else{
		c=ans/n+1;
	}
	if(c%2==1){
		r=ans-(c-1)*n;
	}
	else{
		r=n+1-(ans-(c-1)*n);
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
