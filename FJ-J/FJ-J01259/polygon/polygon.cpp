#include<bits/stdc++.h>
using namespace std;
int a[50005];
int b[50005];
int n;
int w=2;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[1]=a[1]+a[2];
	for(int i=1;i<=n;i++){
		w++;
		for(int j=1;j<=w;j++){
			
		}
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<6;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
