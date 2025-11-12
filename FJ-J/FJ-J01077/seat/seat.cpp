#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[105];
int x=1,y=1,p=1;
void seat(){
	while(y<=m){
		if(y & 1) x=1;
		else x=n;
		while(x<=n&&x>=1){
			if(a[p]==r){
				return ;
			}
			if(y & 1) x++;
			else x--;
			p++;
		}
		y++;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	seat();
	if(x>n) x=n;
	if(y>m) y=m;
	cout<<y<<' '<<x<<endl;
	return 0;
}
