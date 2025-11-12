#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
bool cmp(int x,int y){
	return (x>=y);//从大到小排 
} 
int main(){
	//期望全对得100 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,b,c;
	cin >> n >> m;
	p = (n*m);//共有几个人 
	for(int i=1;i<=p;i++){
		cin >> a[i];
	}
	c = a[1];//记录小R分数 
	sort(a+1,a+p+1,cmp);//排序 
	for(int i=1;i<=p;i++){
		if(a[i]==c){
			p = i;//小R排名第几 
			break;
		}
	}
	b=(p/n)+1;//第几列 
	p%=n;//第几排 
	if(p==0){
		b--;//上一列 
		p = n;//最后一排 
	}
	if(b%2==0){//偶数列是从后往前坐 
		p = (n+1-p);//实际应该在第几排 
	}
	cout << b <<" "<< p;//先输列后输排 
	return 0;
}