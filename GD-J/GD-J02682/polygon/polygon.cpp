#include<bits/stdc++.h> 
using namespace std;
int a[5005],maxn=-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>=500){
		cout<<"sorry,I realy do not know how to do it"; 
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1; 
		}else{
			cout<<0;
		}
	}
	return 0;
}
