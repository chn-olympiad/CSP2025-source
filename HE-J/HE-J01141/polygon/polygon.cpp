#include<bits/stdc++.h> 
using namespace std;
long int n,sum;
long int a[100000005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=3;i++) {
		sum+=a[i];
	}
	sort(a+1,a+4);
	if(a[3]*2<sum){
		cout<<1;
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
