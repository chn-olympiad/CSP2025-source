#include <bits/stdc++.h>
#define  int  long long
using namespace std;
int s[10005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	cin>>s[1];
	int a1=s[1];//小明的成绩 
	for(int i=2;i<=t;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n*m,cmp);
	int pos;
	for(int i=1;i<=t;i++){
		if(s[i]==a1) pos=i;	
	} 
	int c,r;//c列r行 
	if(pos%n==0){//n的倍数 
		c=pos/n;
		if((pos/n)%2==0) r=1;
		else r=n;
	}
	else{//形式为kn+b; 
		int k=pos/n;
		int b=pos%n;
		if(k%2==0) r=b;
		else r=n-b+1;
		c=k+1;
	}
	cout<<c<<" "<<r;
}
