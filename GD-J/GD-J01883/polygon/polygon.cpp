#include<bits/stdc++.h>
using namespace std;
int n,a[5005],k;
long long ans;
int x;
void solve(int y,int num){
	for(int i=y+1;i<k;i++){
		if(a[i]+num>x){
			ans++;
		}
		solve(i,num+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(k=3;k<=n;k++){
		x=a[k];
		for(int i=1;i<k;i++){
			if(a[i]>x){
				ans++;
			}
			solve(i,a[i]);
		}
	}
	cout<<ans;
} 
