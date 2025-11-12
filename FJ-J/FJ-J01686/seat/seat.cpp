#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	int z=a[1];
	sort(a+1,a+s+1,cmp);
	int sum=0;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				sum++;
				if(a[sum]==z){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				sum++;
				if(a[sum]==z){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 

