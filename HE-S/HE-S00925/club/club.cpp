#include<bits/stdc++.h>
using namespace std;
int n,z,fi=0,se=0,th=0,sum[100005];
struct zuo{
	int a,b,c;
}f[100001];
int main(){
freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	memset(sum,0,sizeof(sum));
    cin>>z;
	for(int i=1;i<=z;i++){
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].b>>f[i].c;
		
	if(f[i].a>f[i-1].a){
		int a=f[i-1].a;
		int b=f[i].a;
		int t=0;
		t=a;
		a=b;
		b=t;
	}
		if(f[i].c>f[i-1].c){
		int a=f[i-1].c;
		int b=f[i].c;
		int t=0;
		t=a;
		a=b;
		b=t;
	}
		if(f[i].c>f[i-1].c){
		int a=f[i-1].c;
		int b=f[i].c;
		int t=0;
		t=a;
		a=b;
		b=t;
	}
	}
	}
		if(n%2){
		return 0;
		}
	for(int i=1;i<=n;i++){
		if(fi<(n/2)){
				if(f[i].a>f[i].b&&f[i].a>f[i].c)
	{
		fi++;
		sum[i]+=f[i].a;
	}
		}else
		{
				if(f[i].b>f[i].c)
	{
		se++;
		sum[i]+=f[i].b;
	}else{
		th++;
	sum[i]+=f[i].c;
	}
	
		}
		if(se<(n/2)){
				if(f[i].b>f[i].c&&f[i].b>f[i].a)
	{
		se++;
		sum[i]+=f[i].b;
	}
	
	}else
		{
				if(f[i].a>f[i].c)
	{
		fi++;
		sum[i]+=f[i].a;
	}else
	{
		th++;
	sum[i]+=f[i].c;
	}
		}
		if(th<(n/2)){
				if(f[i].c>f[i].b&&f[i].c>f[i].a)
	{
		th++;
		sum[i]+=f[i].c;
	}
	
	}else
		{
				if(f[i].a>f[i].b)
	{
		fi++;
		sum[i]+=f[i].a;
	}else
	{
		se++;
	sum[i]+=f[i].b;
	}
		}
	}
		
		for(int i=1;i<=z;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}

