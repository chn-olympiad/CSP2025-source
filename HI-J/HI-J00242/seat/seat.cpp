#include<bits/stdc++.h>
using  namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int b=a[0];
	int zwei[n][m];
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				b=a[0];
				int l=0;
				for(int x=1;x<n*m;x++){
					if(a[x]>b){
						b=a[x];
						l=x;
					}
				}
				a[l]=0;
				zwei[j][i]=b;
				if(l==0){
					cout<<i+1<<" "<<j+1<<endl;
				}
			}
		}
		else{
			for(int j=n-1;j>=0;j--){
				b=a[0];
				int l=0;
				for(int x=0;x<n*m;x++){
					if(a[x]>b){
						b=a[x];
						l=x;
					}
				}
				a[l]=0;
				zwei[j][i]=b;
				if(l==0){
					cout<<i+1<<" "<<j+1<<endl;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
