#include<bits/stdc++.h>
using namespace std;
int a[100100][4]={-1};
int b[100100]={0};
int c[100100]={0};
int d[100100]={0};
int n[10];
int all=0;
int club(int p){
	cin>>n[p];
	for(int j=1;j<=n[p];j++){
		for(int q=1;q<=3;q++){
			cin>>a[j][q];
			cout<<a[j][q]<<"  ";
		}
	}
	int y=0;
	y=n[p]/2;
	int one[5]={0},two[5]={0},three[5]={0};
	for(int i=1;i<=n[p];i++){
		for(int j=1;j<=3;j++){ 
			if(a[i][j]>b[i]){
				b[i]=a[i][j];
			}
		}
		for(int j=1;j<=3;j++){
			if(a[i][j]==b[i]){
				if(j==1){
					c[i]=1;
					one[2]+=b[i];
					one[1]++;
				}else if(j==2){
					c[i]=2;
					two[2]+=b[i];
					two[1]++;
				}else if(j==3){
					c[i]=3;
					three[2]+=b[i];
					three[1]++;
				}
			}
		}
	}
	if(one[1]<=y&&two[1]<=y&&three[1]<=y){
		all=one[2]+two[2]+three[2];
	}else all=one[2]+two[2]+three[2]-2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		club(i);
		cout<<all<<endl;
	}
	return 0;
} 
