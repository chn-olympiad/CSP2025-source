#include<bits/stdc++.h>
using namespace std;

int n,m;
//int a[100][100];
struct node{
	int id;
	int score;
	int x,y;
};
node a[11111];
bool cmp(node x,node y){
	return x.score>y.score; 
}
bool cmp2(node x,node y){
	return x.id<y.id;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++)	{
		cin>>a[i].score;
		a[i].id=i;
	}
	sort(a+1,a+l+1,cmp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[cnt].x=i;
				a[cnt].y=j;
				cnt++;
			}
		}else{
			for(int j=m;j>0;j--){
				a[cnt].x=i;
				a[cnt].y=j;
				cnt++;
			}
		}
		
	}
	sort(a+1,a+l+1,cmp2);
	cout<<a[1].x<<" "<<a[1].y;
	return 0;
}
