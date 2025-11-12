#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m;
int seats[105],scores[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);                                          
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);                                   
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>scores[i];
	}
	int k=scores[1];
	sort(scores+1,scores+n*m+1,cmp);
	int num=1;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				//cout<<j<<" 1 "<<i<<"\n";
				if(scores[num]==k){
					cout<<j<<" "<<i;
					return 0;
				}
				num++;
			}
		}
		else{
			for(int i=n;i;i--){
				//cout<<j<<" 2 "<<i<<"\n";
				if(scores[num]==k){
					cout<<j<<" "<<i;
					return 0;
				}
				num++;
			}
		}
	}
	return 0;
	cout<<"rp++!!";
}
