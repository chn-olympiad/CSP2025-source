#include<bits/stdc++.h>
using namespace std;
int n,m,t,p;
int a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++){
		if(a[i]==p){
			t=t-i+1;
			continue;
		}
	}
	if(t%m==0){
		p=t/m;
		if(p%2==0) cout<<p<<" 1"<<endl;
		else cout<<p<<" "<<n<<endl;
	}else{
		p=t/m;
		if(p%2==0) cout<<p+1<<" "<<t%m<<endl;
		else cout<<p+1<<" "<<n-t%m+1<<endl;
	}
	return 0;
}
