#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N+50],sum;
int hs(int s,int qs){
	if(s>=0){
		int num=0;
		for(int i=qs;i<=n;i++){
			int zd=max(a[i],hs(s-1,qs+1))
		}
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		sum+=hs(i,1);
	}
	cout<<sum;
	return 0;
}
