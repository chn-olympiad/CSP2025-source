#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	int sum=0;
	int ans=a[0];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[j]>a[i]){
				sum=a[j];
				a[j]=a[i];
				a[i]=sum;
			}
		}
	}
	int s=1;
	int t=0,b=1;
	for(int k=0;k<n*m/4;k++){
		for(int i=0;i<m;i++){
			if(a[t]==ans){
				cout<<b<<" "<<s;
			}
			t++;
			s++;
		}
		b++;
		if(s>m){
			s--;
		}
		for(int j=m;j>0;j--){
			if(a[t]==ans){
				cout<<b<<" "<<s;
			}
			t++;
			s--;
		}
		b++;
		if(s==0){
			s++;
		}
	}
	return 0;
}

