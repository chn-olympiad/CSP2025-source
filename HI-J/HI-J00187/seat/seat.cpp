#include<bits/stdc++.h>
using namespace std;
int m,n,a[120],r,x,y,b[12][12],ind;
bool cmp(int a,int b){
	if(a>b){
		return true;
	}
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i][j]=a[ind];
			ind++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==r){
				x=i+1;
				y=j+1;
			}
		}
	}
	cout << x <<' ';
	if(x%2==0){
		cout << m-y+1;
	}else{
		cout << y;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
