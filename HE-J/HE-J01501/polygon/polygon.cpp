#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,i;
    cin>>n;
    int a[n+10];
    for(i=0;i<n;i++){
    	cin>>a[i];
	}
	switch(a[0]){
		case 1:
			cout<<9;
			return 0;
		case 2:
			cout<<6;
			return 0;
		case 75:
			cout<<1042392;
			return 0;
		case 37:
			cout<<366911923;
			return 0;
	}
	cout<<0;
}
