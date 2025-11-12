#include<bits/stdc++.h>
using namespace std;
int tong[15];
int main(){
	//写freopen(注意空格！！！),提交记得取消注释，换行用"\n"!!! fc来对比！记得对拍! 
	freopen("number.in", "r",stdin);
	freopen("number.out", "w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		int h=a[i]-'0';	
		if(h>=0 && h<=9){
			tong[h]++; 
		}
	}	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			cout<<i;
		}
	}
	
	
	
	return 0;
} 