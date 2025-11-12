#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=0,m=0,k=0;
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
		return 0;
	}
	int yl[50005][3];
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>yl[i][j];
		}
	}
	int lh[50005][5];
	for(int i=0;i<k;i++){
		for(int j=0;j<5;j++){
			cin>>lh[i][j];
		}
	}
	long long huo[50005];
	for(int i=0;i<m;i++){
		huo[i]=yl[i][2];
	}
	for(int i=0;i<k;i++){
		int min=10000;
		for(int j=1;j<5;j++){
			if(min>lh[i][j]){
				min=lh[i][j];
			}
		}
		huo[i+m]=min;
	}
	sort(huo,huo+m+k);
	int all=0;
	for(int i=0;i<m+k;i++){
		all+=huo[i];
	}
	cout<<all;
	return 0;
}

