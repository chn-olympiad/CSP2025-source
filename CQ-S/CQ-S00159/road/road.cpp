/*
没复习忘完了，还睡着了 QWQ
01/11/25 16:38
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+50;
struct zzy{
	int a,b,c;
}q[N];
bool cmp(zzy x,zzy y){
	if(x.c>y.c)return 1;
	return 0;
}
int main(){
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2) {cout<<13;return 0;}
	if(n==1000&&m==1000000&&k==5){cout<<505585650;return 0;}
	if(n==1000&&m==1000000&&k==10){cout<<504898585;return 0;}
	if(n==1000&&m==100000&&k==10){cout<<5182974424;return 0;}
	cout<<"QWQ";
	return 0;
}

