#include<bits/stdc++.h>
using namespace std;
int num[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	int score=num[1];
	int sum=n*m;
	sort(num+1,num+1+sum,cmp);
	int rk=0;
	for(int i=1;i<=n*m;i++){
		if(num[i]==score){
			rk=i;
		}
	}
	int x=1,y=1;
	for(int i=1;i<rk;i++){
		if((y==n&&x%2==1)||(y==1&&x%2==0)){
			x++;
			continue;
		}
		if(x%2==0){
			y--;
		}
		if(x%2==1){
			y++;
		}
	}
	cout<<x<<" "<<y; 
	return 0;
} 
