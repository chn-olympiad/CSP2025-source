#include<bits/stdc++.h>
using namespace std;
int n,m,a[145],p=0,q=0,zwx=0,zwy=0;
//p记录成绩,q记录排序后排名,zwx,zwy分别为坐标 
int cmp(int thx,int thy){
	return thx>thy; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			q=i;
			break;
		}
	}
	zwx=q/n+q%n;
	int ans=0;
	if(zwx%2==1){
		while(a[ans+(zwx-1)*n]!=p) ans++;
		zwy=ans;
		cout<<zwx<<" "<<zwy<<endl;
		return 0;
	}
	if(zwx%2==0){
		while(a[ans+(zwx-1)*n]!=p) ans++;
		zwy=n-ans+1;
		cout<<zwx<<" "<<zwy<<endl;
		return 0;
	}
	return 0;
}
