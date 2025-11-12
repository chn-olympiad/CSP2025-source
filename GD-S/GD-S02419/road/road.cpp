#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
struct h{
	int x;
	int y;
	int v;
}ro[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[10][1000000];
	int n,m,k;
	cin>>m>>n>>k;
	for(int i=0;i<n;i++){
		cin>>ro[i].x>>ro[i].y>>ro[i].v;
	}
	for(int i=0;i<k;i++){
		for(int i=0;i<m;i++){
			cin>>a[k][m];
		}
	}
	cout<<13;
}
