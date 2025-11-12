#include<bits/stdc++.h> 
using namespace std;
int a[1001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int y,t=0,m=0,k=1;
	cin>>y;
	if(y<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=y;i++){
		cin>>a[i];
		t+=a[i];
		if(m<a[i]){
			m=a[i];
		}
	}
	if(t<=(m*2)) {
		cout<<0;
		return 0;
	}
	else {
		cout<<k;
	}



	return 0;
}
