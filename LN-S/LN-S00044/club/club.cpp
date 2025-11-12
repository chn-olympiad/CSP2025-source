//club.cpp
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int a,b,c,d;
};

bool cmp_1(Node x,Node y){
	return x.a<y.a;
}

bool cmp_2(Node x,Node y){
	return x.b<y.b;
}

bool cmp_3(Node x,Node y){
	return x.c<y.c;
}

void s(){
	int n;
	Node a[10005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		int tmp=max(a[i].a,max(a[i].b,a[i].c));
		if(tmp==a[i].a)a[i].d=1;
		if(tmp==a[i].b)a[i].d=2;
		if(tmp==a[i].c)a[i].d=3;
	}
	sort(a,a+n,cmp_1);
	int sum=0,ret0=0,ret1=0,ret2=0;
	for(int i=0;i<n && sum<=n/2;i++){
		if(a[i].d==1)ret0+=a[i].a;
	}
	
	sort(a,a+n,cmp_2);
	for(int i=0;i<n && sum<=n/2;i++){
		if(a[i].d==2)ret1+=a[i].b;
	}
	
	sort(a,a+n,cmp_3);
	for(int i=0;i<n && sum<=n/2;i++){
		if(a[i].d==3)ret2+=a[i].c;
	}
	
	cout<<ret0+ret1+ret2<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--)s();
}
