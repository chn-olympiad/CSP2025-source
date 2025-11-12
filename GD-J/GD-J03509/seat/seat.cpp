#include <bits/stdc++.h>
using namespace std;
int n,m,a[10005],t,k=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	t=a[0];
	sort(a,a+m*n,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				if(a[k]==t){
					cout<<i<<' '<<j;
					return 0; 
				}
				k++;
			}
		}else{
			for(int j=n;j>0;j--){
				if(a[k]==t){
					cout<<i<<' '<<j;
					return 0; 
				}
				k++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
