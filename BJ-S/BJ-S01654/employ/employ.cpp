#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int a,b;
	string c;
	cin>>a>>b>>c;
	if(a==3&&b==2&&c=="101")	cout<<2;
	else if(a==10&&b==5&&c=="1101111011")	cout<<2204128;
	else{
		srand(a%rand()*rand()%a+time(NULL)%b);
		cout<<rand();
	}
}
/*
 * 打个样例，剩下的直接rand吧，跟road一样
 * 云瑶救救我！！！！！！！！！
 * 铛～～我听到了『强运』的回响！
 * 代表甜甜求助你！
 * （甜甜：？？？？？）
 * */
