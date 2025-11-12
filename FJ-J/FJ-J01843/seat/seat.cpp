#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,**seat,*score;
int main(){
	ifstream in("seat.in");
	ofstream out("seat.out");
	in>>n>>m;
	seat=new int*[n+1];
	for(int i=1;i<=n;i++) seat[i]=new int[m+1];
	score=new int[n*m+1];
	for(int i=1;i<=n*m;i++) in>>score[i];
	int r=score[1];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<i;j++){
			if(score[j]<score[j+1]) swap(score[j],score[j+1]);
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1) seat[j][i]=score[i*n-n+j];
			else seat[n-j+1][i]=score[i*n-n+j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(seat[j][i]==r) out<<i<<" "<<j;
		}
	}
	in.close();
	out.close();
	return 0;
}
