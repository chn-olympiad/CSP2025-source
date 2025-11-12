#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t; //测试数据和成员人数 
	int a1,a2,a3; //满意程度 
	int max=0;
	cin>>t;
	for(int i=1;i<=t;i++){
	cin>>n;
	for(int j=1;j<=n;j++){
	cin>>a1>>a2>>a3;
	if(a1>=a2){
	if(a1>=a3)
	max+=a1;
	else
	if(a3>=a2)
	max+=a3;
    }
    else {
	if(a2>=a3)
    max+=a2;
    else
	max+=a3;}
	}
	cout<<max<<endl;
	max=0;
} //输入输出模块  

	return 0;
}
