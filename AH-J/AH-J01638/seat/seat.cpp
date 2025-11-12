#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int fen;
int it;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	fen=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(a[it]==fen){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				it++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(a[it]==fen){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				it++;
			}
		}
	}
	return 0;
}
