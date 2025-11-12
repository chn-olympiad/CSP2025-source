#include <iostream>
#include <cstring>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	// 
	string a;
	int f=0,s=0;
	cin >> a;
	for(int i = 0;i < a.size();i ++){//数字个数 
		if(a[i]>='0'&&a[i]<='9'){
			s++;
		}
	}
	int n[s];
	for(int i = 0;i < s;i ++)n[i]=0;//初始化 
	
	for(int i = 0;i < a.size();i ++){//数字赋值 
		if(a[i]>='0'&&a[i]<='9'){
			n[f]=(int)a[i]-48;
			f ++; 
		}
	}
	//for(int i = 0;i < s;i ++){//test 
	//	cout << n[i];
	//}
	//打表 
	int q[s];
	for(int i = 0;i < s;i ++){
		if(n[i]==9)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==8)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==7)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==6)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==5)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==4)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==3)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==2)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==1)cout << n[i];
	}
	for(int i = 0;i < s;i ++){
		if(n[i]==0)cout << n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
