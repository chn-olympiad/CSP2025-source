#include <bits/stdc++.h>
using namespace std;
int a[105],f[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]) f[j]++;
			else if(a[i]<a[j]) f[i]++;
		}
	}
	int R=f[1]+1;
	int n1=R%n,n2=R/n;
	if(n1==0){
		if(n2%2==0){
			cout<<n2<<" "<<1<<endl;
		}else{
			cout<<n2<<" "<<n<<endl;
		}
	}else{
		if((n2+1)%2==0){
			cout<<n2+1<<" "<<n-n1+1<<endl;
		}else{
			cout<<n2+1<<" "<<n1;
		}
	}
	return 0;
}

