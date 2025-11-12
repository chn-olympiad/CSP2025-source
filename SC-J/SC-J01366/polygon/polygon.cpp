#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[100005],c;
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];c+=a[i];
	}if(n<3){
		cout<<0;
		return 0;
	}for(int i=1;i<=n;i++){
		if(a[i]*2>=c){
			cout<<0;
			return 0;
		}
	}cout<<1;
	return 0;
}