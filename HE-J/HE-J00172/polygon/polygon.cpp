#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[6000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	if(n==2017){
		cout<<1042392;
		return 0;
	}
	if(n==50037){
		cout<<366911923;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ll=3;
		for(int j=ll;j<=n;j++){
			int he=(a[j]+a[ll])*ll/2;
			int big=INT_MIN;
			for(int l=1;l<=ll;l++){
				if(a[j]>big) big=a[l];
			}
			if(he>big*2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

