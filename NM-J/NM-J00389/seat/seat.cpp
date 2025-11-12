#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1005];
	for(int j=0;j<n*m;j++){
		cin>>a[j];
	}
	int i=a[0],s=0;
	for(int k=0;k<n*m;k++){
		for(int j=k;j<n*m;j++){
			if(a[k]<a[j]){
				if(a[k]==i){
					s=j;
				}
				swap(a[k],a[j]);
			}
		}
	}
	s++;
	if(s%n==0){
		cout<<s/n<<" ";
		if(s/n%2==1){
			cout<<n;
		}else{
			cout<<1;
		}
	}else{
		cout<<s/n+1<<" ";
		if(s/n%2==1){
			cout<<n-(s%n)+1;
		}else{
			cout<<s%n;
		}
	}
	return 0;
}
