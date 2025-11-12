#include<bits/stdc++.h>
using namespace std;
int x,y,e,a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	int n[x][y];
	int m[x*y];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>n[i][j];
			if(i==0&&j==0){
				e=n[i][j];
				a=i;
				b=j;
			}
			if(n[i][j]>e){
				if(b<y-1&&a%2==0){
					b++;
				}else if(b>0&&a%2!=0){
					b--;
				}else if(b==y-1||b==0){
					a++;
				}
			}
		}
	}
	cout<<a+1<<" "<<b+1;
	return 0;
}
