#include<bits/stdc++.h>
using namespace std;
int a[1010],b[1010][1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,q;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
        cin>>a[i];
	}
	x=a[0];
	for(int i=0;i<n*m-1;i++){
        for(int j=0;j<n*m-1;j++){
            if(a[j]>a[j+1]){
                q=a[j];
                a[j]=a[j+1];
                a[j+1]=q;
            }
        }
	}
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][j]=a[i+j*n];
            if(b[i][j]==x){
                cout<<i+1<<" "<<j+1;
                break;
            }
        }
	}
	return 0;
}
