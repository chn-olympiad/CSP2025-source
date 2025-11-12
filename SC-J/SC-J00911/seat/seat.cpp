#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,st,a[1001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++)cin>>a[i];
	st=a[1];
	sort(a+1,a+cnt+1,cmp);
	int x=1,y=0,fl=1;
	for(int i=1;i<=cnt;i++){
		if(fl){
			y++;
			if(y==m+1)y=m,x++,fl=0;
		}else{
			y--;
			if(y==0)y=1,x++,fl=1;
		}
		if(a[i]==st){
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
}