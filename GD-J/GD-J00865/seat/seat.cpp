#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N=155;

bool cmp(int a,int b){
	return a>b;
}
int a[N],k,n,m,cnt=0;

int xx[3]={0,1,0};
int yy[3]={1,0,-1};

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int t;cin>>t;
			if(i==1&&j==1) k=t;
			a[++cnt]=t;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	int now=1,r=1,c=1,bc=1,d=0;
	while(a[now]!=k){
		bc=c;
		r+=xx[d],c+=yy[d];
		if(c==n) d=1;
		if(c==n&&bc==n) d=2;
		if(c==1) d=1;
		if(c==1&&bc==1) d=0;
		now++;
	}
	cout<<r<<" "<<c;
	return 0;
} 
