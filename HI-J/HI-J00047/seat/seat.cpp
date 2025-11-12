#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000],b[10000][10000];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 cin>>n>>m;
	 for(int i=1;i<=n*m;i++){
	 	cin>>a[i];
	 }
	 int e=1;
	 int d=a[1];
	 sort(a+1,a+n*m+1,cmp);
	 	for(int j=1;j<=m;j++){
	 		for(int k=1;k<=n;k++){
	 			b[j][k]=a[e];
	 			e++;
	 			if(b[j][k]==d){
	 				if(j%2!=0){
	 					cout<<j<<" "<<k;
	 					return 0;
					 }else{
					 	cout<<j<<" "<<n-k+1;
					 	return 0;
					 }
				 }
			 }
		 }
	 return 0;
}
