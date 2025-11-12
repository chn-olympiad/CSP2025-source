#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int R=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			R=a[1];	
		}
	}
	sort(a+1,a+1+n*m,cmp);
	int y=1,s=1,id=1;
	while(a[id]!=R){
		if(a[id]==R){
			cout<<s<<" "<<y;
			break;
		}
		if(s%2!=0){
			y++;
			if(y==n+1){
				s++;
				y=n;
			}
		}
		else{
			y--;
			if(y==0){
				s++;
				y=1;
			}
		}
		id++;
	}
	cout<<s<<" "<<y;
	return 0;
}
