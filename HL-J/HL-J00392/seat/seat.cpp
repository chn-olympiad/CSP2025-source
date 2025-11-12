#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[999];
bool aa(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int b[999][n];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}x=a[0];
	sort(a,a+n*m,aa);
	for(int i=0,p=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				b[i][j]=a[p];
				p++;
			}
		}else{
			for(int j=m-1;j>=0;j--){
				b[i][j]=a[p];
				p++;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i][j]==x){
				cout<<i+1<<' '<<j+1;break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}