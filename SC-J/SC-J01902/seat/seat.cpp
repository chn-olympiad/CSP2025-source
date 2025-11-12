#include<bits/stdc++.h>
using namespace std;
int n,m,a[109],q,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	q=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>0;i--){//cout<<a[i]<<"\n";
		if(a[i]==q){
			q=n*m-i+1;
			break;
		}
	}//cout<<q;
	s=q/n;
	q%=n;
	
	if(q==0){
		if(s%2==0){
			cout<<s<<" "<<1;
		}else{
			cout<<s<<" "<<n;
		}
	}else{
		if(s%2==0){
			cout<<s+1<<" "<<q;
		}else{
			cout<<s+1<<" "<<n-q+1;
		}
	}
	
	return 0;
}