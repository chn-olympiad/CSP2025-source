#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],hao;
	sort(a+1,a+1+n*m);
	for (int i=1;i<=n*m;i++){
		if(a[i]==x){
			hao=n*m-i+1;
			break;
		}
	}
	if(hao%n==0){
		if((hao/n)&1){
			cout<<hao/n<<" "<<n<<endl;
		}
		else{
			cout<<hao/n<<" "<<1<<endl;
		}
	}
	else{
		if((hao/n+1)&1){
			cout<<hao/n+1<<" "<<hao%n<<endl;
		}
		else{
			cout<<hao/n+1<<" "<<n-hao%n+1<<endl;
		}
	}
}
