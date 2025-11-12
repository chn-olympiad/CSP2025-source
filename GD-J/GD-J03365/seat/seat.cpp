#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=1,y=1;
int jn=0;
int a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int pp=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	bool f=1;
	for(int i=1;i<=n*m;i++){
		jn++;
		if(a[i]==pp){
			cout<<y<<" "<<x;
			return 0;
		}
		if(jn<n){
			if(f)x++;
			else x--;
		}
		else{
			jn=0;
			if(f==1)f=0;
			else f=1;
			y++;
		}
	}
	return 0;
}
