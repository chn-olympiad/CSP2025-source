#include<bits/stdc++.h>
using namespace std;
int n,a[5010],c,z,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			c+=a[j];
			if(c>a[j]*2) ans++;
		}
		z=0;c=0;
	}
//	for(int i=0;i<n;i++){
//		if(a[i]+a[i+1]>a[i+3]) ans++;
//		if(a[i]+a[i+2]>a[i+3]) ans++;
//	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}