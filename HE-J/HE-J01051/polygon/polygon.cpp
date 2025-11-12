#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[25000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,he=0,maxs=-1;
	for(int i=3;i<=n;i++){
		for(int k=1;k<=i;k++){
			he+=a[k];//cout<<he<<" ";
			if(a[k]>maxs) maxs=a[k];
		}
		if(he>2*maxs) ans++;
		for(int j=1;j<=n-i+1;j++){
			he=he-a[j]+a[j+i-1];
			if(a[j+i]>maxs) maxs=a[j+i-1];
			if(he>2*maxs) ans++;
			cout<<ans<<" ";
		}
		cout<<endl;
		he=0,maxs=-1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
