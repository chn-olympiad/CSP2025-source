#include<bits/stdc++.h>
using namespace std;
int t,n,d;
struct node{
	int a,b,c,f;//f表示是否入职 
};
bool cmp_a(node x,node y){
	if (x.a>y.a)
		return 1;
	return 0;
}
bool cmp_b(node x,node y){
	if (x.b>y.b)
		return 1;
	return 0;
}
bool cmp_c(node x,node y){
	if (x.c>y.c)
		return 1;
	return 0;
}
node a[100005];
void comp(){
	sort(a+1,a+n+1,cmp_a);
	for(int i=1,s=n/2;i<=n,s;i++){
		if(a[i].f==0){
			d+=a[i].a;
			a[i].f=1;//已占用
			s--;
			
		} 
	}
	sort(a+1,a+n+1,cmp_b);
	for(int i=1,s=n/2;i<=n,s;i++){
		if(a[i].f==0){
			d+=a[i].b;
			a[i].f=2;
			s--;
		}
		else if(a[i].f==1 && a[i].b>a[i].a){
			d=d-a[i].a+a[i].b;//细节防越界 
		}
	}
	sort(a+1,a+n+1,cmp_c);
	for(int i=1,s=n/2;i<=n,s;i++){
		if(a[i].f==0){
			d+=a[i].c;
			a[i].f=3;
			s--;
		}
		else if(a[i].f==1 && a[i].c>a[i].a){
			d=d-a[i].a+a[i].c;//细节防越界 
		}
		else if(a[i].f==2 && a[i].c>a[i].b){
			d=d-a[i].b+a[i].c;//细节防越界 
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].a>>a[j].b>>a[j].c;
		}
		comp();
		cout<<d;
	}
	return 0;
}
