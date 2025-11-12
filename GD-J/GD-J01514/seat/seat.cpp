#include<bits/stdc++.h>
using namespace std;
int n,m;
int t,x;
int a[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				t++;
				if(a[t]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				t++;
				if(a[t]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

