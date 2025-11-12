#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,num;
};
bool cmp(node a,node b){
	return a.num > b.num ;
}
int n,m;
node a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int su=n*m;
	for(int i=1;i<=su;i++){
		cin>>a[i].num;
		a[i].id =i;
	}
	int r;
	sort(a+1,a+1+su,cmp);
	for(int i=1;;i++){
		if(a[i].id ==1){
			r=i;
			break;
		}
    }
    //cout<<r;
   	int x=1,y=1;
	for(int i=1;i<r;i++){
		if(x%2==1&&y==m){
			//cout<<y;
			x++; 
		}
		else if(x%2==0&&y==1){
			//cout<<y;
			x++;
		}
		else if(x%2==1){
			//cout<<y;
			y++;	
		}
		else{
			//cout<<y;
			y--;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}