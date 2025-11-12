#include<iostream>
#include<map>
#include<cmath>
using namespace std;
int x;
int a[110];
struct M{
	int r,c;
};
map<int,M> ma;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		if(i==0){
			cin>>x;
		}
		else{
			cin>>a[i];
		}
	}
	for(int i=0;i<m*n-1;i++){
		for(int j=0;j<m*n;j++){
			if(a[i+1]>a[i]){
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=0;i<m*n-1;i++){
		int tmp1=(i+1)%n;
		int tmp2=(i+n)/n;
		M t;
		t.c=tmp2;
		if(tmp2%2==0){
			if(tmp1!=0)t.r=n+1-tmp1;
			else t.r=1;
		}
		else{
			if(tmp1!=0)t.r=tmp1;
			else t.r=n;
		}
		ma[i]=t;
	}
	for(int i=0;i<n*m;i++){
		if(x>a[i]){
			cout<<ma[i].c<<" "<<ma[i].r;
			return 0;
		}
	}
}
