#include<bits/stdc++.h>
using namespace std;
long long a[200];
int n,m;
unsigned long long hang,lie,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]){
			ans++;
		}
	}
	lie=ans/m+1;
	if(lie%2==0){
		hang=n-ans%m;
	}
	else{
		hang=ans%m+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
} 