#include<bits/stdc++.h>
using namespace std;
int seat[100][100];
int a[100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int R=a[0];
	sort(a,a+n*m,cmp);
	bool flag=1;
	int i=0,j=0;
	int cnt=0;
	int xun=n*m;
	while(xun--){
		if(flag==1){
			if(i<n-1){
				seat[i][j]=a[cnt];
				cnt++;
				i++;
			}else{
				seat[i][j]=a[cnt];
				cnt++;
				j++;
				flag=0;
			}
		}else{
			if(i>0){
				seat[i][j]=a[cnt];
				cnt++;
				i--;
			}else{
				seat[i][j]=a[cnt];
				cnt++;
				j++;
				flag=1;
			}
		}
		for(int k=0;k<n;k++){
			for(int t=0;t<m;t++){
				if(seat[k][t]==R){
					cout<<t+1<<" "<<k+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
