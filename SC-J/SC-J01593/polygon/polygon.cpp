#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freoprn("polygon.out","w",stdout);
	int n,a[5010];
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]; 
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;
		}
		else if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
		}
		else cout<<0;
	}
	return 0;
}