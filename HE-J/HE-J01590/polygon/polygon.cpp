#include<bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n,t=0,ans = 0;
	cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)t+=a[i];
	if(t>a[n-1]*2){
		ans++;
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
