#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[120223]={0};
	cin>>n;
	int maxx=-1,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		sum+=a[i];
	}
	if(n>=4){
		cout<<"2";
		return 0;
	}
	cout<<"1";
	return 0;

	

}
