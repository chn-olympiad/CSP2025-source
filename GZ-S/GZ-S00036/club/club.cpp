//GZ-S00036 六盘水市第二十四中学 冉哲睿
#include<bits/stdc++.h>
using namespace std;
int maxn,t,n,A,B;
struct aa{
	int a1,a2,a3;
}a[100001];
bool cmp1(aa x,aa y){
	return x.a1>=y.a1;
}
bool cmp2(aa x,aa y){
	return abs(x.a1-x.a2)>=abs(y.a1-y.a2);
}
void ff(int r,int x,int y,int h){
	if(r>n){
		maxn=h;
		return;
	}
	if(x==n/2)ff(r+1,x,y+1,h+a[r].a2);
	else if(y==n/2)ff(r+1,x+1,y,h+a[r].a1);
	else if(a[r].a1>a[r].a2)ff(r+1,x+1,y,h+a[r].a1);
	else if(a[r].a1<a[r].a2)ff(r+1,x,y+1,h+a[r].a2);
}
void f(int r,int x,int y,int z,int h){
	if(r>n){
		maxn=max(maxn,h);
		return;
	}
	if(x<n/2)f(r+1,x+1,y,z,h+a[r].a1);
	if(y<n/2)f(r+1,x,y+1,z,h+a[r].a2);
	if(z<n/2)f(r+1,x,y,z+1,h+a[r].a3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		A=0;
		B=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a3!=0)A=1,B=1;
			if(a[i].a2!=0)A=1;
		}maxn=0;
		if(A==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=n/2;i>=1;i--)maxn+=a[i].a1;
		}else if(B==0){
			sort(a+1,a+n+1,cmp2);
			ff(1,0,0,0);
		}else f(1,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
