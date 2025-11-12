#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return f*x;
}
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[105],c,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			b=i;
			break;
		}
	}
	//cout<<b;
	cout<<(b-1)/n+1<<' ';
	if((b-1)/n%2==1){
		cout<<n-(b-1)%n;
	}else{
		cout<<(b-1)%n+1;
	}	
	return 0;
}

