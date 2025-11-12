//seat AC 1 2 3 st

#include<iostream>
#include<string>
using namespace std;
using ll = long long;

//int score[110];//最大 n*m = 100

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;cin>>n>>m;
	
	//input 1 -> n*m
	
	int f;cin>>f; // first score即小明分数
	int cnt = 1;//比小明大的人数 + 1   :  小明排位序号 
	for(int i = 2;i<=n*m;i++) //the input without the first  2->n*m
	{
		int inp;
		cin>>inp;
		
		if(inp>f)cnt++;
	}
	
	//以cnt计算小明的排位坐标
	int x,y;//小名坐标x,y    max:m,n
	x = cnt/n + bool(cnt%n != 0); // cnt/n向上取整
	if(x%2 == 1){//奇数行 
		y =  cnt%n;
		if(y == 0)y = n;
	}
	else{//偶数行 
		y =  cnt%n;
		if(y == 0)y = n;
		y = n+1-y;
	}
	
	cout<<x<<' '<<y;
}
