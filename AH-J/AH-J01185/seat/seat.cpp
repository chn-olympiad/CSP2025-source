#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[210];
long long b[15][15];
bool cmp(int h,int g){
	return h>g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=(n*m);
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+c,cmp);
	int v=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				if(a[v]==x){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				b[i][j]=a[v];
				v++;
			}
		}else{
			for(int j=m-1;j>=0;j--){
				if(a[v]==x){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				b[i][j]=a[v];
				v++;
			}
		}
	}
	
	return 0;
}


