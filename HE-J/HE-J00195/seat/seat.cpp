#include<bits/stdc++.h>
using namespace  std;
int n,m,r,k=1;
int a[1001],b[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]==r){
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	int j=1,i=1;
	while(i<n){
		if(i!=1)i++;
		if(j!=1)j++;
		while(j<=m){
			b[j][i]=a[k];
			if(b[j][i]==r){
				cout<<i<<" "<<j;
				return 0;
		    }
		    j++;
			k++;
		}
		i++;
		j--;
		while(j>=1){
			b[j][i]=a[k];
			if(b[j][i]==r){
				cout<<i<<" "<<j;
				return 0;
			}
			j--;
			k++;
		}
	}
	return 0;
}
