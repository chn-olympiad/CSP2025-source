#include<bits/stdc++.h>
using namespace std;
struct xx{
	int sc,id;
}x[105];
bool cmp(xx a,xx b){
	return a.sc>b.sc;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>x[i].sc;
		x[i].id=i+1;
	}
	sort(x,x+n*m,cmp);
	int ix=0;
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				if(x[ix].id==1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				ix++;
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				if(x[ix].id==1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
				ix++;
			}
		}
	}
	return 0;
}

