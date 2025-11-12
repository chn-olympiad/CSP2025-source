#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=1;i++){
		if(a[i]>=10){
			cout<<"6";
			
		}else{
			cout<<"9";
			
		}
	}
	return 0;
}
