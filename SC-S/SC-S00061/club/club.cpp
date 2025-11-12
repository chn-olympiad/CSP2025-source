#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int n;
	cin >> n;
	int xsmyd[300005] ={};
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		for(int jishu = 1;jishu <= a;jishu++){
			for(int b = 1;b <= 3;b++){
				cin >> xsmyd[(jishu-1)*3+b];
			}
		}
		int zdmyd = 0;
		for(int suoy = 1;suoy <= a*3;suoy+=3){
			sort(xsmyd+suoy,xsmyd+suoy+3,cmp);
			zdmyd += xsmyd[suoy];
		}
		cout << zdmyd << endl;
	}
return 0;
}
