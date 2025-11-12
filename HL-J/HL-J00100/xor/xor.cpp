#include <bits/stdc++.h>
using namespace std;
int n,a[50010],sum=0;
long long k;
bool check(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans=ans^a[i];
		
	}
	if(ans==k) return true;
	else return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(check(l,r)){
				sum++;
				l=r+1;
			}
		}
	}
	cout<<sum;

	return 0;
	
}