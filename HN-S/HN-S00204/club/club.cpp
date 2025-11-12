#include<bits/stdc++.h>
#define f(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
int t,n,a[100005],b[100005],c[100005],s;
int fx(int i,int x,int y,int z,int s){
	if(i>n)return s;
	int k=0;
	if(x<n/2)k=fx(i+1,x+1,y,z,s+a[i]);
	if(y<n/2)k=max(k,fx(i+1,x,y+1,z,s+b[i]));
	if(z<n/2)k=max(k,fx(i+1,x,y,z+1,s+c[i]));
	return k;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		f(i,1,n)scanf("%d%d%d",a+i,b+i,c+i);
		s=0;
		if(n<=10){
			cout<<fx(1,0,0,0,0)<<endl;
			continue;
		}
		sort(a+1,a+n+1,[](int x,int y){return x>y;});
		f(i,1,n/2)s+=a[i];
		cout<<s<<endl;
	}
	return 0;
}
