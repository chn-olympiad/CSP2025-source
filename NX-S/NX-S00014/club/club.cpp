#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream("club.in");
	ofstream("club.out");
	int t,n,m[5][100000][3],a[3]={0,0,0},b[3]={0,0,0};
	long long int score=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>m[i][j][0]>>m[i][j][1]>>m[i][j][2];
		}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			if(m[i][j][0]>m[i][j][1]&&m[i][j][1]>m[i][j][2]){
				a[0]=0;a[1]=1;a[2]=2;
			}else if(m[i][j][0]>m[i][j][2]&&m[i][j][2]>m[i][j][1]){
				a[0]=0;a[1]=2;a[2]=1;
			}else if(m[i][j][1]>m[i][j][0]&&m[i][j][0]>m[i][j][2]){
				a[0]=1;a[1]=0;a[2]=2;
			}else if(m[i][j][1]>m[i][j][2]&&m[i][j][2]>m[i][j][0]){
				a[0]=1;a[1]=2;a[2]=0;
			}else if(m[i][j][2]>m[i][j][1]&&m[i][j][1]>m[i][j][0]){
				a[0]=2;a[1]=1;a[2]=0;
			}else if(m[i][j][2]>m[i][j][0]&&m[i][j][0]>m[i][j][1]){
				a[0]=2;a[1]=0;a[2]=1;
			}
			if(b[a[0]]<n/2){
				score+=m[i][j][a[1]];
				b[a[0]]+=1;
			}else{
				score+=m[i][j][a[0]];
			}
		}cout<<score;score=0;
	}
}
