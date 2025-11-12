#include<bits/stdc++.h>
#define N 5005
using namespace std;
int n,mx,sum,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>mx)mx=a[i];
		sum+=a[i];
	}
	if(sum/mx>=2&&sum%mx!=0)cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}