#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=1,y=1;
struct node{
	int sc;
	int num;
}stu[110];
bool cmp(node a,node b){
	return a.sc>b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>stu[i].sc;
		stu[i].num=i;
	}
	sort(stu+1,stu+n*m+1,cmp);
	int tail=1;
	while(stu[tail].num!=1){
		if(x%2==1)y++;
		else if(x%2==0)y--;
		if(y>n || y<1){
			x++;
			if(y>n)y=n;
			if(y<1)y=1;
		}
		tail++;
	}
	cout<<x<<" "<<y;
	/*for(int i=1;i<=n*m;i++){
		cout<<stu[i].sc;
	}*/
	return 0;
}
