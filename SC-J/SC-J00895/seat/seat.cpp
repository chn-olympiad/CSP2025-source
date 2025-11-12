#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int goa=a[1];
	sort(a+1,a+n*m+1,cmp);
	int num=0;
	for(int i=1;i<=n*m;i++){// 先走横行 再走纵列
		if(a[i]==goa) num=i;
	}
	int y=num/n;
	int x=num%n;
	if(x){
		if(y%2){// 此时为偶列 
			 cout<<y+1<<" "<<n-x+1;
			 return 0;
		}
		else{
			cout<<y+1<<" "<<x;
			return 0;
		}
	}
	if(y%2){
		cout<<y<<" "<<n; 
		return 0;
	}
	else cout<<y<<" "<<1;
	
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92