#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;//记录行列
	for(int i=0;i<a*b;i++)cin>>s[i];
	c=s[0];//记录小R的位置
	sort(s,s+(a*b));//从小到大排序，因此要反过来
	while(s[d]!=c)d++;//寻找R的位置 
	d=(a*b)-d;//反转，现在是正向的了
	e=d/a;//记录R在第几列
	d=d%a;//记录R在第几行
	if(e%2==0){
		cout<<e+1<<' '<<d;
	} 
	else{
		cout<<e+1<<' '<<a-d;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

2 2
98 97 99 100

2 2
99 97 98 100
*/
