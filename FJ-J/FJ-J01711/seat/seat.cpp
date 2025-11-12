#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];//n行m列，学生成绩
int cnt[110],b;// 记录坐标 ,记录排名 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		 cin>>a[i];
	}
	cnt[a[1]]=1;//记录下标 
	sort(a+1,a+n*m+1,cmp);//排序 
	for(int i=1;i<=n*m;i++){
		if(cnt[a[i]]==1){//找到排名 
			b=i;
			break;
		}
	}
	int c,r;//列，行 
	if(b%n==0){
		c=b/n;
	}else{
		c=b/n+1;
	}
	if(c%2==1){//如果为单列 
		r=b-(c-1)*n; //行 
	}else{//如果为双列 
		r=n-(b-(c-1)*n)+1;//行 
	}
	cout<<c<<" "<<r;//输出 
	return 0;
} 
