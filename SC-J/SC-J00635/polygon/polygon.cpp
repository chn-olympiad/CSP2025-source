#include<bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
	   cin>>a[i];
	   sum+=a[i];
	}
	sort(a+1,a+n+1);
    if(sum>2*a[n])cout<<1;
    else cout<<0;
	fclose(stdin);fclose(stdout);
	return 0;
}