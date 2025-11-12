#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[105],z=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			z++;
		}
	}
	cout<<ceil(z*1.0/m)<<" ";
	if(int(ceil(z*1.0/m))%2==1){
		
		if(z%m==0){
			
			cout<<m;
		}else{
			cout<<z<<"  ";
			cout<<z%m;
		}
	}else{
		cout<<m-(z%m)+1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
