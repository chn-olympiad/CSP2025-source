/*#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node{
	int a1,a2,a3;
	int x;
	int ls;
	int fl;
	int jf;
	int er;
}z[250000];
int f=0;
int q(int z,int x,int c){
	if(z>x){
		if(z>c){
			return 1;
		}
		if(c>z){
			return 3;
		}
		if(z==c){
			if(f%2==0)
				return 1;
			else{
				return 3;
			}
		}
	}
	if(z<x){
		if(x>c){
			return 2;
		}
		if(x<c){
			return 3;
		}
		if(x==c){
			if(f%2==0)
				return 2;
			else{
				return 3;
			}
		}
	}
	if(z==x){
		if(c>z){
			return 3;
			
		}
		if(c==z){
			if(f%2==0)
				return 1;
			else{
				return 3;
			}
		}
		if(c<z)
		{
			if(f%2==0)
				return 2;
			else{
				return 3;
			}
		}
	}
}
int tree(int z,int x,int c){
	if(z>x){
		if(x>c){
			return 2;
		}
		if(c>x){
			return 3;
		}
		if(x==c){
			if(f%2==0)
				return x;
			else{
				return 3;
			}
		}
	}
	if(z<x){
		if(z>c){
			return 1;
		}
		if(z<c){
			return 3;
		}
		if(z==c){
			if(f%2==0)
				return 1;
			else{
				return 3;
			}
		}
	}
	if(z==x){
		
			if(f%2==0)
				return 1;
			else{
				return 3;
			}
		
		
	}
}
long long p[4];
long long fl[250001];
long long qw[250001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		memset(p,0,sizeof(p));
		memset(qw,0,sizeof(qw));
		memset(fl,0,sizeof(fl));
		memset(z,0,sizeof(z));
		long long n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,s,d;
			cin>>a>>s>>d;
			z[i].a1=a;
			z[i].a2=s;
			z[i].a3=d;
			int w=max(a,s);
			z[i].x=max(w,d);
			w=min(a,s);
			w=min(w,d);
			z[i].jf=a+s+d-w-z[i].x;
			fl[i]=z[i].x-z[i].jf;
			z[i].ls=q(a,s,d);
			int u=tree(a,s,d);
			z[i].er=u;
			p[z[i].ls]++;
			qw[u]++;
		}
	
		int pass=0;
		for(int i=1;i<=3;i++){
			if(p[i]>n/2){
				pass=i;
			}
		}
		long long c=0;
			for(int i=1;i<=n;i++){
				c+=z[i].x;
			}
		if(pass==0){
			
			cout<<c<<endl;
		}
		else{
			int g=p[pass];
			sort(fl+1,fl+1+n);
			for(int i=1;i<=p[pass]-n/2;i++){
				c-=fl[i];
			}
			cout<<c<<endl;
			
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} **/
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
struct node{
	int a1,a2,a3;
	int f;
	int h;
}z[250000];
bool cp(node a,node b){
	return a.f<b.f;
}
int p[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	int k;
	cin>>k;
	
	for(int i=1;i<=k;i++){
		memset(p,0,sizeof(p));
		memset(z,0,sizeof(z));
		long long n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,s,d;
			cin>>a>>s>>d;
			int f=max(max(a,s),d);
			int j=min(a,min(s,d));
			z[i].a1=f;
			z[i].a2=(a+s+d-f-j);
			z[i].f=z[i].a1-z[i].a2;
			
			z[i].a1=f;
			z[i].a2=(a+s+d-f-j);
			if(z[i].a1==a){
				z[i].h=1;
			}
			if(z[i].a1==d){
				z[i].h=2;
			}
			if(z[i].a1==s){
				z[i].h=3;
			}
		}
		sort(z+1,1+z+n,cp);
		
		int oi=n;
		int c=0;
		while(p[1]<n/2&&p[2]<n/2&&p[3]<n/2){
			if(z[oi].h==1){
				p[1]++;
			}
			if(z[oi].a1==2){
				p[2]++;
			}
			if(z[oi].a1==3){
				p[3]++;
			}
			c+=z[oi].a1;
			oi--;
			if(oi==0){
				break;
			}
		}
		while(oi>0){
			c+=z[oi].a2;
			oi--;
		}
		cout<<c<<endl;}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
