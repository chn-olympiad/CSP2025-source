#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t){
		int n;//n表示新成员的数量 
		cin>>n;
		int a[10001];
		int m[3]={1,2,3};//分别表示第i个新成员对第1,2,3个部门的满意程度 
		for(int i=0;i<=3;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		int zu1=0;
		int zu2=0;
		int zu3=0;
		if(a[1]=m[0]){
			zu1++;
		}else if(a[2]=m[1]){
			zu2++;
		}else{
			zu3++;
		}
		int fangan[3]={zu1,zu2,zu3};
		if(zu1>n/2){
			zu1=zu1-(n/2);
		}
		if(zu2>n/2){
			zu2=zu2-(n/2);
		}
		if(zu3>n/2){
			zu3=zu3-(n/2);
		}
		sort(fangan+1,fangan+1+n);
		cout<<fangan<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
