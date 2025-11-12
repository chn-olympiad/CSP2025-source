#include<bits/stdc++.h>
using namespace std;
//T2
//警惕精度错误，时间空间错误等，数组不要超过10个，空间不要超过1^7，时间最好不要达到10^8，不用endl，scanf不能读取string和bool
//freopen记得不要注释掉了，不要写fclose，不要关闭流同步
//记得写有返回值的函数写return，main函数只能返回int
//getline不能接在要换行的cin后面，不然会读到换行符。
//考试结束的时候才能登出程序回收系统，不要更换浏览器。
//在代码前面写上一定量的无意义注释
struct nihaoadent{
	int t;
	bool flag=0;
}nihaoa[150];
bool cmp(nihaoadent a,nihaoadent b){
	return a.t>b.t;
}
int n,m,k=0;
bool flag=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nihaoa[0].flag=1;
	for(int i=0;i<n*m;i++){
		cin>>nihaoa[i].t;
	}
	sort(nihaoa,nihaoa+n*m,cmp);
//	for(int i=0;i<n*m;i++){
//		cout<<nihaoa[i].t<<" "<<nihaoa[i].flag<<endl;
//	}
	for(int i=0;i<n;i++){
		int j;
		if(i%2==0)j=0,flag=0;
		else j=m-1,flag=1;
		for(;;){
			if(flag&&j<0)break;
			else if(!flag&&j>=m)break;
			if(nihaoa[k].flag==1){
				cout<<i+1<<" "<<j+1;
				return 0;
			}
			k++;
			if(flag)j--;
			else j++;
		}
	}
	return 0;
}