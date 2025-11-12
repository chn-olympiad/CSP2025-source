/* UNDEBUGGED */
/* REDIRECTED */

#include<iostream>
#include<cstring>
//#include<cstdio>
#include<algorithm>
#include<cmath>
//#include<array>
//#define debug CERTAINLY
using namespace std;

bool cmp(int a,int b){
	return a>b;
}


const size_t MAXLEN=10;
//int pts[MAXLEN+5][MAXLEN+5];//1-based
int pts[MAXLEN*MAXLEN+5];//1-based 
//array<array<int, MAXLEN+5>, MAXLEN+5> pts;
int n,m,rpts;

/* babe i dont know how to sort
   double-dimension array through stl lib */

int main(){
	//optimise i/o
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	//redirect i/o
	freopen("seat.in","r",stdin);
	#ifndef debug
	freopen("seat.out","w",stdout);
	#endif
	
	cin>>n>>m;
//	for(size_t i=1;i<=n;++i)for(size_t j=1;j<=m;++j)cin>>pts[n][m];
	for(size_t i=1;i<=n*m;++i){
		cin>>pts[i];
	}
	rpts=pts[1];
	
//	sort(&pts[1][1],&pts[1][1]+n*m);
	sort(pts+1,pts+n*m+1,cmp);
//	sort(pts.begin(),pts.end(),cmp);
	for(size_t k=1;k<=n*m;++k){
		size_t j=ceil((double)k/n);//向上取整
		size_t i=(k%n==0)?n:(k%n); 
//		size_t reali=n-i+1;
		bool up2down=(j%2==1);
		if(!up2down)i=n-i+1;
		
//		printf("[%lld][%lld] %d\n",i,j,pts[k]);
		if(pts[k]==rpts){
			cout<<j<<' '<<i;
			break;
		}
	}

    return 0;
}



