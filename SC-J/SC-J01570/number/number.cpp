#include<bits/stdc++.h>
using namespace std;
//T1
//警惕精度错误，时间空间错误等，数组不要超过10个，空间不要超过1^7，时间最好不要达到10^8，不用endl，scanf不能读取string和bool
//freopen记得不要注释掉了，不要写fclose，不要关闭流同步
//记得写有返回值的函数写return，main函数只能返回int
//getline不能接在要换行的cin后面，不然会读到换行符。
//考试结束的时候才能登出程序回收系统，不要更换浏览器。
//在代码前面写上一定量的无意义注释
vector<int>arr;
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9')arr.push_back(str[i]-'0');
	}
	sort(arr.rbegin(),arr.rend());
	if(arr[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
	}
	return 0;
}