#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=0;
int a[1001];
bool cmp(int a,int b){
	return a>b;
}
bool f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			s=i;
			break;
		}
	}
	while(s--){
		if(f==1)y++;
		else if(f==0)y--;
		if(y==n&&s>0&&f==1)x++,f=0,s--;
		else if(y==1&&s>0&&f==0)x++,f=1,s--;
	}
	cout<<x<<' '<<y;
	return 0;
}