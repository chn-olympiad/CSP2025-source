#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=3;++i){
		scanf("%d",&a[i]);
	}
	if((a[1]+a[2])>a[3] && (a[1]+a[3])>a[2] && (a[2]+a[3])>a[1]) ans++;
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}