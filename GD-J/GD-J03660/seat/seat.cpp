#include<bits/stdc++.h>
using namespace std;
int b[50][50];
int a[110],r[10];
int n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	r[1]=a[1];
	int num=1;
	sort(a+1,a+x+1,cmp);

	for(int i=1;i<=n;i++){ 
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[num]==r[1]){
					cout<<i<<" "<<j;
					return 0; 
				}
				num++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[num]==r[1]){
					cout<<i<<" "<<j;
					return 0; 
				}
				num++;
			}
		}
		
	}
	
	return 0;
}
