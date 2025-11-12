#include<bits/stdc++.h>
using namespace std;
long long a[15][15],n,m,b[120],p;
bool aa(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i]; 
	}
	p=b[1];
	sort(b+1,b+1+n,aa);
	int q=0,s=0,x=1,y=1;
	while(1){
		q++;
		//cout<<x<<" "<<y<<" "<<b[q]<<endl;
		if(b[q]==p){
			cout<<x<<" "<<y;
			return 0;
		}
		if(x==n||x==1&&q!=1){
			y++;
		}
		else if(s){
			x--;
		}else{
			x++;
		}
	}
	return 0;
} 
