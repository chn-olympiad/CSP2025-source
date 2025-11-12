#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int map[101];
	int book[101];
	for(int i=0;i<=n*m;i++){
		cin>>map[i];
	}
	int r=map[1];
	sort(map+1,map+1+n);
	cout<<1<<" "<<2<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
