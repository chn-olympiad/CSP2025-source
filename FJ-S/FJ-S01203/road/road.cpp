#include<bits/stdc++.h>
using namespace std;
int t,n,cnt=0,sum=0,w;
long long a[205];
int s[205];

void check(x){
	int t;
	for(int i=0;i<n*3;i++){
	if(a[i]>a[i-1])
	t=a[i];
	a[i]=a[i-1];
	a[i-1]=a[i];
	check(x);
 }
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
//存储	
	cin>>n;
	for(int i=0;i<n*3;i++){
	cin>>a[i];
  }


//最大值 
  

 
//主要部分 
	  
    check;


//输出测试 
	for(int i=0;i<n*3;i++){
	cout<<a[i]<<' ';
  }



	return 0;
}
