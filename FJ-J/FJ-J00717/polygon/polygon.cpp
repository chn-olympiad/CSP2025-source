#include<bits/stdc++.h>
using namespace std;
int a[1000001],n,cnt,k[1000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	k[0]=a[0];
	int f=1;
	for(int i=1;i<n-1;i++){
		k[f]=a[i];
		for(int j=0;j<f;j++){
			k[f+j+1]=k[j]+a[i];
			if(k[f+j+1]>a[i+1])cnt++;
			if(k[j]>a[i+1])cnt++;
		}
		f*=2;
		f++;
	}
	cout<<cnt;
}
