#include<bits/stdc++.h>
using namespace std;
int n,m,s,r;
int cmp(int a,int b){
	return a>b;
}
bool pan(int i){
	if((i/m)%2==0){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);//文件读写 
	cin>>n>>m;
	s=n*m;
	int a[n*m]={};
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+s,cmp);
	for(int i=0;i<s;i++){
		if(a[i]==r){
			if(pan(i)){
				cout<<i/m+1<<" "<<i%m+1;//当是偶数列时，输出列数与行数 
				return 0;//减少时间复杂度 
			}else{
				cout<<i/m+1<<" "<<n-i%m;//当前列是奇数列时，输出列数与行数 
				return 0;//减少时间复杂度 
			}
		}
	}
	return 0;
}
