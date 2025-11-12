#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[5010],k;
void f(int i,int maxi,int s){
	if(i==n&&s>2*maxi){
			k++;
			k=(k)%998244353;
			return;
		}
	if(i==n) return;
	for(int j=i+1;j<=n;j++){
		f(j,maxi=max(maxi,a[j]),s+a[j]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i,a[i],a[i]);
	}cout<<k;
}
