#include <bits/stdc++.h>
using namespace std;

struct X{
	int a;
	char sur='*';
};

bool cmp(X a,X b){
	return a.a>b.a;
}

int main(){
	ifstream fin("D:/GD-J03392/seat/seat.in");
	ofstream fout("D:/GD-J03392/seat/seat.out");
	int n,m;
	fin>>n>>m;
	X x[n*m];
	x[0].sur='#';
	for(int i=0;i<n*m;i++){
		fin>>x[i].a;
	}
	sort(x,x+n*m,cmp);
	int q=1,t=1,j=1;
	for(int i=0;i<n*m;i++,j+=q){
		if(x[i].sur=='#') break;
		if((j==n && q>0) || (j==1 && q<0)){
			q*=-1;
			t++;
			j-=q;
		}
	}
	fout<<t<<' '<<j;
	return 0;
}
