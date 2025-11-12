#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+len+1,cmp);
	int s;
	for(int i=1;i<=len;i++){
		if(a[i]==f){
			s=i;
			break;
		}
	}
	int c;
	int r;
	int cnt=s%n;
	if(cnt==0) c=s/n;
	else c=s/n+1;
	if(cnt==0){
		int p=s/n;
		if(p%2==0) r=1;
		else r=n;
	}
	else{
		if(c%2==0) r=n-cnt+1;
		else r=cnt;
	}
	cout<<c<<" "<<r;
	return 0;
}


