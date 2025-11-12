#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0)R=a[i];
		
	}
	for(int i=0;i<n*m-2;i++)for(int j=i;j<n*m-1;j++)if(a[j]<a[j+1])swap(a[j],a[j+1]);
	bool b=1;
	int k=-1;
	for(int m1=1;m1<=m;m1++){
		if(b==1){
			for(int n1=1;n1<=n;n1++){
				k++;
				if(a[k]==R){
					cout<<m1<<" "<<n1;
					return 0;
				}
			}
		}
		else {
			for(int n1=n;n1>=1;n1--){
				k++;
				if(a[k]==R){
					cout<<m1<<" "<<n1;
					return 0;
				}
			}
		}
		b=!b;
	}
	return 0;
}
