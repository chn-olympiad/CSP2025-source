#include<bits/stdc++.h>
using namespace std;
struct aaa{
	int st;
	int to;
	int cs;
};
struct bbb{
	int re;
	int ro;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	aaa a[m+1]={};
	for(int i=0;i<m;i++){
		cin>>a[i].st>>a[i].to>>a[i].cs;
	}
	int cost=0;
	int mn=1e9;
	for(int i=0;i<m;i++){
		if(a[i].cs<mn){
			mn=a[i].cs;
		}
	}
	cost+=mn;
	bbb b[k+1]={};
	for(int i=0;i<k;i++){
		cin>>b[i].re;
		cin>>b[i].ro;
	}
	mn=1e9;
	int f;
	for(int i=0;i<k;i++){
		if(b[i].re<mn){
			mn=b[i].re;
			f=i;
		}
	}
	cost+=mn;
	cost+=b[f].ro;
	cout<<cost;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
