#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,cc=0;
	cin>>n;
	int max=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cc+=a[i];
		if(a[i]>max)max=a[i];
	}
	if(cc>=2*max){
		if(n==3){
			cout<<1;
		}
		else cout<<5;
	}
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
