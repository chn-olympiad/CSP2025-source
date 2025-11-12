#include<bits/stdc++.h>
using namespace std;
struct No{
char ch;
int k;
}a[1000];
bool cmp(No a,No b){
	return a.k>b.k;	
}
int main(){
int n,m,v=1;
cin>>n>>m;
char ch[550];
for(int i=1;i<=n;i++)cin>>a[i].ch;
if(m==1){
int s=0;
for(int i=1;i<=n;i++)if(a[i].ch=='1')s++;
cout<<s;
return 0;	
}
for(int i=1;i<=n;i++)cin>>a[i].k;
sort(a+1,a+n+1,cmp);
for(int i=1;i<=n;i++){
	if(a[i].ch=='1'&&a[i].k+1>=n)m--;	
	if(m==0)break;
}
int b[1000]={0},maxx=-999999;
for(int i=1;i<=n;i++){
	b[a[i].k]++;
	if(a[i].k>maxx)maxx=a[i].k;
}
for(int i=1;i<=maxx;i++){
	if(b[i]>0){
		int l=1;
		for(int j=1;j<=b[i];i++)l*=j;
		v+=l;
	}
}
cout<<v;
	return 0;	
}
