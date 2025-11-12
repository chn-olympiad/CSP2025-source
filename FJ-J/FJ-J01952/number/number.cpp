#include<bits/stdc++.h> 
using namespace std;
string s;//串s 
long f=1;//位置

long sum=0;//有几个数字 
long numb[1000010];//数字
bool cmp(int d,int e){
	return d>e;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;//sorry，scanf不会写string类型 
//-----------------------------------------------
	 for(int i=0;i<=s.size();i++){//走一遍 
	 	if(s[i]>=48&&s[i]<=57){//是数字 
	 		numb[f]=s[i]-'0';//存进去 
	 		f++;//++
			 sum++;//加1 
	 	}
	 }
	 sort(numb+1,numb+1+sum,cmp);
	 //只走一遍，o(n) 
//-----------------------------------------------
	 //for(int i=1;i<=sum;i++) cout<<numb[i]<<" ";//看一下对不对
	 for(int i=1;i<=sum;i++) cout<<numb[i]; 
	return 0;
}
