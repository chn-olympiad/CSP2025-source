#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt;
int f(int x,int y){
	int ans=1;
	for(int i=1;i<=y;i++) ans*=x;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=f(2,n)-1;l++){
		int ans=0,ma=INT_MIN;
		for(int i=l,j=1;i;i/=2,j++){
			if(i%2){
				ans+=a[j];
				ma=max(a[j],ma);
			}
		}
		if(ma*2<ans) cnt++;
	}
	cout<<cnt%989%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
