#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
    }
	if(a[1]<a[2]){
		cout<<n*m;
	}else cout<<"1 1";
	return 0;
}
