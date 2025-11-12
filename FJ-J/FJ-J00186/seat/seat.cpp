#include<bits/stdc++.h>
using namespace std;

int n, m;				//行，列 
int student, xiaor,b;	//student学生总数，xiaor小r的分数，b小r的名次 
int x,y; 				//x行，y列
int a[105];

bool cmp(int c, int d){
	return c > d;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	//输入 
	cin >> n >> m;
	student = n*m;
	for(int i=1;i<=student;i++)cin >> a[i];
	
	xiaor = a[1];	//记录小r的成绩 
	
	sort(a+1,a+student+1,cmp);	//排序 
	
	//记录小r的名次 
	for(int i=1;i<=student;i++){
		if(a[i]==xiaor)b=i;
	}
	
	//计算坐标 
	x=b%n;
	y=b/n;
	if(x>0)y++;
	
	if(y%2==0){//如果是偶数列 
		x=b-((y-1)*n);
		x=n+1-x;
	}else{
		if(x==0)x=n;
	}
	
	cout<<y<<" "<<x;//先列后行 
	
	return 0;
}
