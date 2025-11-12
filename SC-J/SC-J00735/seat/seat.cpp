#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,pos;
struct stu{
	int a,b;
}c[110];
bool cmp(stu u,stu v){
	return u.a>v.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>c[i].a;
	c[0].b=1;
	sort(c,c+n*m,cmp);
	
	for(int y=1;y<=m;y++){
		for(int k=1;k<=n;k++){
			//cout<<x<<" "<<y<<'\n';
			if(c[pos++].b==1){
				cout<<y<<" "<<x;
				break;
			}
			if(k==n)continue;
			if(y%2)x++;
			else x--;
		}	
	
	}
	return 0;
}