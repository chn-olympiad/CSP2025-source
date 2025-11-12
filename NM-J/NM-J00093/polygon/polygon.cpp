#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int sum=0,max=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>max){
			max=a[i];
		}
	}
	if(n<3)
		cout<<"0";
	else if(n==3){
		if(sum<=max+max)
			cout<<"0";
		else
			cout<<"1";
	}
	else{
        cout<<"0";
	}
	return 0;
}
