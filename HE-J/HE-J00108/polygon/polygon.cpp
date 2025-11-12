#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[50005],maxn;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],a[i+1]);
	} 
	if(n==3){
		if(a[1]+a[2]+a[3]>maxn){
			cout<<1;
		    return 0;
		}
		else {
		    cout<<0;
			return 0;
	    }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
