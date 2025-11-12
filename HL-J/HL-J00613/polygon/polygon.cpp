#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int ans,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]<a[i+1]){
			cnt=a[i];
			a[i]=a[i+1];
			a[i+1]=cnt;
		}
	}
	int all=0;
	int maxa=0;
	int num=0;
	for(int i=0;i<n;i++){
		all+=a[i];
		num+=1;
		for(int j=0;j<n;j++){
			if(num>=3 && maxa*2>all){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
