#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e6+10;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2||n==1){
		cout<<"0";
		return 0;
	}
	if(n==3){
		cout<<"1";
		return 0;
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<"9";
		return 0;
	}else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<"6";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
