#include<bits/stdc++.h>
using namespace std;

int n;
int a[10005];
int ans;
int b[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(n==3){
			if(2*max(a[1],max(a[2],a[3]))<a[1]+a[2]+a[3]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
		
	}
	sort(a,a+n+1);
	
	return 0;
}
