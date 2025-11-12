#include<bits/stdc++.h>
using namespace std;
struct Node{
	int id;
	int score;
	bool operator<(const Node &other)const{
		return score>other.score;
	}
}a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	int x=1,y=1,number=0;
	while(true){
		number++;
		if(a[number].id==1){
			cout<<y<<" "<<x;
			return 0;
		}
		if( (y&1&&x==n) || ((!(y&1))&&x==1) )y++;
		else{
			if(y&1)x++;
			else x--;
		}
	}
	return 0;
}
