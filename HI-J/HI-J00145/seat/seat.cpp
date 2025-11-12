#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[110];
int ans;
int Rx,Ry;
int findRSite(int R){
	for(int i=1;i<=n*m;i++){
		if(a[i]==R)return i;
	}
	return n*m;
}
int upfloat(int x,int y){//x/y向上取整 
	int w=0;
	if(x%y!=0)w=1;
	int r=x/y;
	return r+w; 
}
int solveRy(int Rx,int RSite){
	int b=Rx%2;//1单排正序0双排倒序 
	if(b){//单排正序 
		if(RSite%n==0)return m;
		else return RSite%n;
	}
	else {//双排倒序 
		return n-(RSite%n)+1;
	}
}
bool cmp(int a1,int b1){
	return a1>b1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==m&&n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);//其中a1为小R CSP-J 2025 第一轮的成绩
	}
	int R=a[1]; 
	sort(a+1,a+1+n*m,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";////
	//cout<<endl;////
	int RSite=findRSite(R);//[Warning] format '%d' expects argument of type 'int', but argument 2 has type 'int*' [-Wformat=]
	//cout<<RSite;//////
	Rx=upfloat(RSite,n);//列 
	Ry=solveRy(Rx,RSite);//行 
	printf("%d %d",Rx,Ry);
	return 0;
}
