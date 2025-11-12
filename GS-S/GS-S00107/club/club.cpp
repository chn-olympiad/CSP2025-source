#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int a[M];
int b[M];
int c[M];
int h[M];
int tot=0;
int ans=1,bns=1;
int e[M];
bool cmp(int n,int m){
	return n>m;
}
int main(){
	int n;
	cin>>n;
	int sone=0,stwo=0,sthr=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		sone+=a[i];
		stwo+=b[i];
		sthr+=c[i];
	}
	if(sone==0&&stwo==0&&sthr!=0){
		sort(c+1,c+n+1,cmp);
			for(int i=1;i<=n/2;i++){
			tot+=c[i];
			}
	}
	if(sone==0&&stwo!=0&&sthr==0){
		sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
			tot+=b[i];
			}
	}
	if(sone!=0&&stwo==0&&sthr==0){
		sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
			tot+=a[i];
			}
	}
	if(n==2){
		e[1]=a[1]+b[2];
		e[2]=a[1]+c[2];
		e[3]=b[1]+a[2];
		e[4]=b[1]+c[2];
		e[5]=c[1]+a[2];
		e[6]=c[1]+b[2];
		for(int i=1;i<=6;i++){
			tot=max(tot,e[i]);
		}
	}

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cout<<tot;
	return 0;
	
}

