#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
using namespace std;
int iu(int a,int b){
	a-=b;
	if(a > b){
		iu(a,b);
	}
	return a;
}
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.ans","w",stdout);
	int n,m,mn;
	cin >> n >> m;mn = n * m;
	int a[n][m];
	int b[mn];
	for(int k = 0;k < mn;k++){
		int win;cin >> win;
		b[k] = win;
	}
	int R = b[0];
	for(int i = 0;i < mn;i++ ){
		for(int j = i+1;j < mn;j++){
			if(b[j] > b[i]){
				int c = b[j];
				b[j] = b[i];
				b[i] = c;
			}
		}
	}
	int num = 1;
	for(int i = 0;i < mn;i ++){
		if(b[i]>R){
			num++;
		}
	}
	int c,r;
	//c = num/n;
	if(num <= n){
		c = 1;
	}else{
		c = num/n+1;
	}
	num-=n*(c-1);
	if(c%2 ==0){
		r = n-num+1;
	}else{
		r = num;
	}
	cout << c << " " << r;
	/*V(^-^)V!
	1: 2 2 
	   99 100 97 98
	2: 3 3
	     94 95 96 97 98 99 100 93 92       */
	fclose(stdin);
	fclose(stdout);
	return 0;
}
