#include<bits/stdc++.h>
using namespace std;
int a[100000]={0};
bool cnt(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cnt);
	int f=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			f=i;
			break;
		}
	}
	int j=1;
	int x=1,y=1;
	int flag=0;
	while(j!=f){
		if(flag==0&&x==n){
			y++;
			flag=1;
			j++;
			continue;
		}
		if(flag==1&&x==1){
			y++;
			flag=0;
			j++;
			continue;
		}
		if(flag==0){
			x++;
			j++;
			continue;
		}
		if(flag==1){
			x--;
			j++;
		}
	}
	cout<<y<<" "<<x;
}
