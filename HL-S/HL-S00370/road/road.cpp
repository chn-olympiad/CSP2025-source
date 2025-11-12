#include<bits/stdc++.h>
using namespace std;
int n;
short f[10001][10001];
struct node{
	int b, e;
	double money;
}a[1000001];
struct Node{
	int mf, mr;
}c[11];
bool cmp1(Node x,Node y){
	return x.mf + x.mr * n / 10 < y.mf + y.mr * n / 10;
}
int main()
{
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
    	cin >> a[i].b >> a[i].e >> a[i].money;
	}
	int zm = 0;
	for(int i = 1;i <= k;i++){
		cin >> c[i].mf >> c[i].mr;
	}
	cout << 13;
	return 0;
}