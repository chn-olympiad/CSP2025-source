#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int sum;
struct city{
	int c1;
	int c2;
	int w;
}a[100050];
int cn,c[10005][49810];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].c1>>a[i].c2>>a[i].w;
	}
	if(k==0){
		for(int i=0;i<n;i++){
			sum+=a[i].w;
		}
		cout<<sum;
	}else if(k>1&&k<=5&&m<=100000){
		for(int i=0;i<k;i++){
			cin>>cn;
			for(int j=0;j<n;j++){
				cin>>c[i][j];
			}
		}
		for(int i=0;i<n;i++){
			sum+=a[i].w;
		}
		cout<<sum;
	}else if(k<=5&&m<=1000000&&n<=1000){
		for(int i=0;i<k;i++){
			cin>>cn;
			for(int j=0;j<n;j++){
				cin>>c[i][j];
			}
		}
		for(int i=0;i<n;i++){
			sum+=a[i].w;
		}
		cout<<sum;
	}else if(k<=5&&m<=1000000&&n<=10000){
			for(int i=0;i<k;i++){
			cin>>cn;
			for(int j=0;j<n;j++){
				cin>>c[i][j];
			}
		}
		for(int i=0;i<n;i++){
			sum+=a[i].w;
		}
		cout<<sum;
	}else if(k<=10&&m<=1000000&&n<=1000){
			for(int i=0;i<k;i++){
			cin>>cn;
			for(int j=0;j<n;j++){
				cin>>c[i][j];
			}
		}
		for(int i=0;i<n;i++){
			sum+=a[i].w;
		}
		cout<<sum;
	}
	return 0;
}
