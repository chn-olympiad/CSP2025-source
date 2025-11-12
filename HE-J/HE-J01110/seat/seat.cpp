#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int n,m;int i=1;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for(i<=n*m;i++){
    	cin>>a[i];
	}
	sort(a,a+n*m);
	a[n*m]=12;
	cout<<i<<" "<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

