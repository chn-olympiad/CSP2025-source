#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t;
int n;
struct node{
	int a,b,c;
}p[N];
bool cmp(node a,node b){
	return a.a>b.a;
}
bool cmp1(node a,node b){
	return a.b>b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag=true,flag1=true;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].b!=0)flag=false;
			if(p[i].c!=0)flag1=false;
		}
		if(flag==true&&flag1==true){
			sort(p+1,p+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=p[i].a;
			}
			cout<<sum<<endl;
		}else if(n==2){
			cout<<max(max(p[1].a+p[2].b,p[1].a+p[2].c),max(max(p[1].b+p[2].a,p[1].b+p[2].c),max(p[1].c+p[2].a,p[1].c+p[2].b)));
		}
	}
	return 0;
}
