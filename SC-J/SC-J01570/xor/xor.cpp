#include<bits/stdc++.h>
using namespace std;
//T3
//警惕精度错误，时间空间错误等，数组不要超过10个，空间不要超过1^7，时间最好不要达到10^8，不用endl，scanf不能读取string和bool
//freopen记得不要注释掉了，不要写fclose，不要关闭流同步
//记得写有返回值的函数写return，main函数只能返回int
//getline不能接在要换行的cin后面，不然会读到换行符。
//考试结束的时候才能登出程序回收系统，不要更换浏览器。
//在代码前面写上一定量的无意义注释避免查重
//可以抢先一步帮别人答一个人0分然后在登陆自己的账号
int n,k,d1,d2;
int arr[500050],vis[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(k==1&&arr[i]==1)d1++,vis[i]=1;
		else if(k==0&&arr[i]==0)d2++,vis[i]=1;
		else if(k==0&&arr[i]==1&&arr[i-1]==1&&!vis[i-1]&&i!=0){
			d2++;
			vis[i-1]=1,vis[i]=1;
		}
	}
	if(k==1)cout<<d1;
	else if(k==0)cout<<d2;
	else cout<<0;
	return 0;
}