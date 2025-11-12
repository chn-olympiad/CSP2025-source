#include<iostream>
#include<cmath>
#include<algorithm>
#define N 100000
using namespace std;
int a[3][N];
struct R{
	int a,who;
	bool operator<(R p){
		if(this->a<p.a){
			return 1;
		}
		return 0;
	}
}r[3][N*2];
int myf(int wh,int we){
	for(int i=0;i<n;i++){
		if(r[we][i].who==wh){
			return r[we][i].a;
		}
	}
}
int n,m,k,kw;
int main(){
	int t,n,pt[2];
	long long ans;
	cin>>t;
	while(t--){
		pt[0]=0;
		pt[1]=1;
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>r[0][i].a>>r[1][i].a>>r[2][i].a;
			r[0][i].who=i;
			r[1][i].who=i;
		}
		sort(r[0],r[0]+n);
		sort(r[1],r[1]+n);
		for(int i=0;i<n;i++){
			if(r[0][pt[0]]>r[1][pt[1]]){
				r[2][pt[0]+pt[1]].a=r[0][pt[0]++];
			}
			else{
				r[2][pt[0]+pt[1]].a=r[1][pt[1]++];
			}
		}
		for(int i=0;i<n;i++){
			if(r[0][pt[0]]>r[1][pt[1]]){
				if(r[0][pt[0]]-myf(r[0][pt[0]].who,1)<){
			}
		}
	}
	return 0;
}