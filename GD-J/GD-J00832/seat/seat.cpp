#include<bits/stdc++.h>
using namespace std;
int n,m,aa[110],p,w;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++){
		cin>>aa[i];
	}
	int z=aa[1];
	sort(aa+1,aa+1+q);
	for(int i=q;i>=1;i--){
		if(aa[i]==z){
			p=i;
		}
	}
	p=q-p+1;
	int a=p/n;
	int b=p%n;
	if(b!=0)w=1;
	if((a+w)%2==0){
	if(b!=0)cout<<a+1<<" "<<n-b+1<<endl;	
	else cout<<a<<" "<<n-b-1<<endl;	
	}
	else{
		if(b!=0)cout<<a+1<<" "<<b<<endl;
		else cout<<a<<" "<<n<<endl;
	}

	return 0;
}
