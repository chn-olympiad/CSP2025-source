#include<bits/stdc++.h> 
using namespace std;
const int N= 1e6 + 10; 
int p[N];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//int a1 = 0,a2 = 0,a3 = 0,a4 = 0,a5 = 0,a6 = 0,a7 = 0,a8 = 0,a9 = 0,a0 = 0;
	string a;
	int cnt = 0;
	cin >> a;
	for(int i = 0; i < a.size();i++){
		if(a[i] >= '0' && a[i] <= '9'){
			p[cnt] = a[i] - '0';
			cnt ++;
		}
	}
	/*
		if(a[i] == '0'){
			a0 ++;
			continue;
		} 
		if(a[i] == '1'){
			a1 ++;
			continue;
		} 
		if(a[i] == '2'){
			a2 ++;
			continue;
		} 
		if(a[i] == '3'){
			a3 ++;
			continue;
		} 
		if(a[i] == '4'){
			a4 ++;
			continue;
		} 
		if(a[i] == '5'){
			a5 ++;
			continue;
		} 
		if(a[i] == '6'){
			a6 ++;
			continue;
		} 
		if(a[i] == '7'){
			a7 ++;
			continue;
		} 
		if(a[i] == '8'){
			a8 ++;
			continue;
		} 
		if(a[i] == '9'){
			a9 ++;
			continue;
		} 
	}
	*/
	sort(p,p+cnt+1,cmp);
	for(int i = 0;i < cnt;i++){
		printf("%d",p[i]);
	} 
	/* 
	for(int i = 0 ;i < a9;i++) printf("%d",9);
	for(int i = 0 ;i < a8;i++) printf("%d",8);
	for(int i = 0 ;i < a7;i++) printf("%d",7);
	for(int i = 0 ;i < a6;i++) printf("%d",6);
	for(int i = 0 ;i < a5;i++) printf("%d",5);
	for(int i = 0 ;i < a4;i++) printf("%d",4);
	for(int i = 0 ;i < a3;i++) printf("%d",3);
	for(int i = 0 ;i < a2;i++) printf("%d",2);
	for(int i = 0 ;i < a1;i++) printf("%d",1);
	for(int i = 0 ;i < a0;i++) printf("%d",0);
	*/
	return 0;
}
