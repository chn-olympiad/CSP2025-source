#include<bits/stdc++.h>
using namespace std;
int n,m,r,k;
int a[1005],b[15][15];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
		r=a[1];
		sort(a+1,a+n*m,cmp);
		int i=1,j=1;
		while(k%2==1 && j<n){
			b[i][j]=a[i];
			k++;
			if(a[i]>=r){
				cout<<j<<" "<<i;
				return 0;
			}
			j++;
			k++;
		}
		i++;
		j--;
			while(i<=m){
		while(i<=n){
			b[i][j]=a[i]; 
			k++;
			if(a[i]>=r){
				cout<<j<<" "<<i;
				return 0;
			}
			j++;
			
		}
	}
	
	
	return 0;	
}
