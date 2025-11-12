#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",std.in)
	freopen("seat.out","w",std.out)
	int n,m,ans,y;
	cin>>n>>m;
	int x=n*m;
	string l[x];
	cin>>y>>l[x-1];
	l[1]=y;
	for(int i=0;i<x;i++){
		ans=max l[i],l[i+1];
		i++;
	}
}
