#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],r,x=1,y=1,f=1;
bool b;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==1&&f==-1&&!b){
			f=1;
			y++;
			b=true;
		}
		else if(x==n&&f==1&&!b){
			f=-1;
			y++;
			b=true;
		}else x+=f,b=false;
	}
}

