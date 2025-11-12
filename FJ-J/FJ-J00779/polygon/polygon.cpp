#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n,m,w,ans,c,r;
int a[110];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ans = 1;
	for(int i = n;i>=3;i--){
		ans = ans*i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
