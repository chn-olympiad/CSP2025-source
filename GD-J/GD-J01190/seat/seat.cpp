#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a > b;
}

int n,m;
int stu[110];
int seat[20][20];
int r;
int k = 0;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n * m;i++){
		cin>>stu[i];
	}
	r = stu[0];
	sort(stu,stu + n * m,cmp);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i%2 == 0){
				seat[j][i] = stu[k];
			}else{
				seat[n - j - 1][i] = stu[k];
			}
			k++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(seat[i][j] == r){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
} 
