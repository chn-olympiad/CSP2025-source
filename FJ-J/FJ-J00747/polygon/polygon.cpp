#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s,k;
void d(int i){
	i++;
	if(i==n)return;
	s+=a[i];
	for(int l=i+1;l<=n;l++){
		if(a[l]>=s)break;
		k++;
	}
	d(i);
	s-=a[i];
	d(i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	d(0);
	cout<<k; 
} 
