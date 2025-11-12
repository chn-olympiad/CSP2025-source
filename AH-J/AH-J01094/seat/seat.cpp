#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int l=0;
    int r=0;
    int maxn=0;
    int f=0;
    int t=0;
    
	cin>>n>>m;
	int k=n*m;
	int a[n][m];
	int b[k];
	
	for(int i=0;i<k;i++){
		cin>>b[i];
	}
	int Rseat=b[0];
	for(int j=0;j<k;j++){
	    for(int i=r;i<k;i++){
		    if(b[i]>maxn){
		    	maxn=b[i];
		    	l=i;
		    }
		}
		r++;
		t=b[f];
		b[f]=b[l];
		b[l]=t;
		f+=1;
		maxn=0;
	}
	r=0;
	int i=0;
    for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			a[i][j]=b[r];
			r+=1;
			
		}
		i++;
		for(int j=n-1;j>=0;j--){
			a[i][j]=b[r];
			r+=1;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[j][i]==Rseat){
				cout << j+1 <<" "<< i+1 << endl;
			}
		}
	}
	return 0;
}
