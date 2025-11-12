#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#define INF 1000000
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int a1,a2,a3;
	cin>>a1>>a2>>a3;
	if((a1+a2+a3)>2*(max(max(a1,a2),a3))) cout<<1;
	else cout<<0;
	return 0;
}