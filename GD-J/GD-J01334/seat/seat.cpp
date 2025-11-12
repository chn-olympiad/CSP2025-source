//seat able
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=107;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	int x=a[1],dx=1,dy=1;
	bool fl=1;
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++){
		bool op=0;
		if(a[i]==x) break;
		if(dy==n&&dx%2==1) dx++,fl=0,op=1;
		if(dy==1&&dx%2==0) dx++,fl=1,op=1;
		if(op==0){
			if(fl) dy++;
			else dy--;
		}
	}
	cout<<dx<<" "<<dy;
	return 0;
}
