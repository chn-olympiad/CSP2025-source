#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int f[15][15];//0
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	int a[sum+1];
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int cur=a[1];//小R成绩
	sort(a+1,a+sum+1,cmp);
	int mingci;
	for(int i=1;i<=sum;i++){
		if(a[i]==cur){
			mingci=i;
			break;
		}
	}
	int x=1,y=1;//x行 y列
	int step=1;//当前名次
	f[0][1]=1;
	while(true){
		if(step==mingci){
			break;
		}
		step++;
		f[x][y]=1;
		if(f[x-1][y]==1){
			if(x==n){
				y++;
			}else{
				x++; 
			}
		}else{
			if(x==1){
				y++;
			}else{
				x--;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
