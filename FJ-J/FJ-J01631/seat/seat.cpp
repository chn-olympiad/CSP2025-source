//seat.cpp
#include<iostream>
#include<algorithm>

int seat[100];
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,R,cnt=0;
	bool flag=1;
	cin>>n>>m>>R;
	seat[0]=R;
	for(i=1;i<m*n;i++){
		cin>>seat[i];
	}
	stable_sort(seat,seat+i,[](int a,int b){return a>b;});
	for(i=1;i<=m && flag;i++){
		if(i%2){
			for(j=1;j<=n && flag;j++,cnt++){
				if(seat[cnt]==R){
					cout<<i<<' '<<j;
					flag=0;
				}
			}
		}
		else{
			for(j=n;j>=1 && flag;j--,cnt++){
				if(seat[cnt]==R){
					cout<<i<<' '<<j;
					flag=0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

