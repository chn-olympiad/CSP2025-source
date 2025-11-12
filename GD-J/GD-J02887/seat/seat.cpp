#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n*m+5;
	int a[q];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i];
//	}
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				if(a[k]==R){
					c=i,r=j;
				}
				k++;
			}	
		}else{
			for(int j=1;j<=m;j++){
				if(a[k]==R){
					c=i,r=j;
				}
				k++;
			}
		}
	}
	cout<<c<<" "<<r;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
