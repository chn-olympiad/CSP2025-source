#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[4],f=0,max=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f+=a[i];
		if(a[i]>max){
			max=a[i];
		}
	}
	if(n<3||f<=max*2){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
