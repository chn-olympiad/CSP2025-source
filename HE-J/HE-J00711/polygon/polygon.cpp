#include<bits/stdc++.h>
using namespace std;

int n;
int a[5200];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
	}
	sort(a,a+n);
	int maxx;
	maxx=a[n-1];
	if(n==3){
		if(a[0]+a[1]+a[2] > a[2]+a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
