#include<bits/stdc++.h>
using namespace std;
//int in(){
//	char c=getchar();
//	int f=1,k=0;
//	while(c<'0'||c>'9'){
//		if(c=='-')f=-1;
//		c=getchar();
//	}
//	while(c<='9'&&c>='0'){
//		k*=10;
//		k+=c-'0';
//		c=getchar();
//	}
//	return k*f;
//}

int a[1007];
int n,m;
int pm;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k;
	cin>>k;
	a[1]=k;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int x=n*m; 
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k)pm=i;
	}
	int l=(pm+n-1)/n;
	if(l%2==1){
		int y=pm-n*(l-1);
		cout<<l<<" "<<y;
	}else{
		int y=n*l-pm+1;
		cout<<l<<" "<<y;
	}
	return 0;
}
