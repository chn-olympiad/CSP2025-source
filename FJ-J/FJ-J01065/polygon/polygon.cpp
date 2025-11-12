#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],c[100005],sum,mx,ans;
void vb(int l,int b){
	long long k=0;

	for(int i=3;i<n;i++){	
		k+=a[i];
		if(mx<a[i]){
			mx=a[i];
		}
		vb(i,i+1);
	}
	if(k>mx*2){
		ans++;
	}
	l--;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	cin>>n;	mx=a[1];
	if(n<=3){
		cout<<0;
	}
	else{
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		vb(i,3);
	}
	cout<<((ans%998)%244)%353;	
	}


}


