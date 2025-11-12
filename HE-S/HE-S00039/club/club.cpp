#include<bits/stdc++.h>
using namespace std;
int i;
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>i;
	int temp[3];
	int mtemp=0;
	int l[3];
	int number=0;
	int list[i];
	for(int z=1;z<=i;z++){
		cin>>n;
	int a[n][3];
	for(int r=1;r<=n;r++){
		for(int j=1;j<=3;j++){
			cin>>a[r][j];
		}
	}
	
	for(int t=1;t<=n;t++){
		for(int k=1;k<=3;k++){
			temp[k]=a[t][k];
		}
		mtemp=max(temp[1],temp[2]);
		number+=max(mtemp,temp[3]);
	}
	list[z]=number;
	}
	for(int f=1;f<=i;f++){
		cout<<list[f];
	}
}
