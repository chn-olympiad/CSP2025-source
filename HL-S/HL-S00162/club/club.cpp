#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
const int M = 1000;
int maxn(int a,int b,int c){
	if(a>b && a>c) return 0;
	else if(b>a && b>c) return 1;
	else return 2;
}
int maxn1(int a,int b,int c){
	if(a>b && a>c && b>c) return 1;
	else if(b>a && b>c && a>c) return 0;
	else return 2; 
}
int mth(int a,int b,int c){
	if(a>b && a>c) return a;
	else if(b>a && b>c) return b;
	else return c;
}
int mth1(int a,int b,int c){
	if(a>b && a>c && b>c) return b;
	else if(b>a && b>c && a>c) return a;
	else return c; 
}
int cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n;
	while(n--){
		struct data{
			int xa,xb,xc;
		}a[M];
		int clubs[3] = {0,0,0};
		int p;
		cin >> p;
		for(int i = 0;i<p;i++){
			cin >> a[i].xa >> a[i].xb >> a[i].xc;
		}
		for(int i = 0;i<p;i++){
			int v = maxn(a[i].xa,a[i].xb,a[i].xc);
			if(clubs[v] < p/2){
				clubs[v]++;
				cnt+=mth(a[i].xa,a[i].xb,a[i].xc);
			}
			else{
				v = maxn1(a[i].xa,a[i].xb,a[i].xc);
				clubs[v]++;
				cnt+=mth1(a[i].xa,a[i].xb,a[i].xc);
			}
		}
		cout<<cnt<<endl;
		cnt = 0;
	}
	return 0;
}
