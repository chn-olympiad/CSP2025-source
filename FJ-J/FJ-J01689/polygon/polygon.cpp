#include<bits/stdc++.h>
using namespace std;
int a,m[100001],cnt=0;
void f(int num,int chang){
	if(num<=a){
	   if(chang>m[num]&&num>3&&m[num-1]!=0){
		 cnt++;
	}
	
	   for(int i=num+1;i<=a;i++){
	      f(i,chang+m[i+1]);
	}
  }
}
int main(){
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		scanf("%d",&m[i]);
	}
	sort(m+1,m+a+1);
	f(1,0);
	printf("%d",cnt);
	return 0;
}
