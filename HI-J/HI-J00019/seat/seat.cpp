#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];
int n,m;
void sap(){
	for(int i=0;i<n*m;i++)
		for(int j=1;j<n*m;j++){
			if(a[j]>a[j-1]){
				int x=a[j];
				a[j]=a[j-1];
				a[j-1]=x;
			}
		}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int ax=a[0];
	sap();
	int x=1,y=1,j=1;
	for(int i=0;i<n*m;i++){
		if(x%2!=0){
			if(a[i]==ax){
				cout<<x<<" "<<y;
			}
			y++;
		}else{
			int ba=m-j;
			if(a[i]==ax){
				cout<<x<<" "<<(ba+1);
			}
		}
		if(j==m){
			j=1;
			y=1;
			x++;
		}else{
			j++;
		}
	}
	
	return 0;
}

