#include<bits/stdc++.h>
using namespace std;
int a[5005],s;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxn=-1111,c;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		c+=a[i];
	}
	if(c>a[n]){
		s++;
	}
	cout<<s;
	return 0;
}