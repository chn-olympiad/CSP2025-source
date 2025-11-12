#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[50005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>2*(max(max(a[1],a[2]),a[3]))){
			cout<<1<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<n-2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
