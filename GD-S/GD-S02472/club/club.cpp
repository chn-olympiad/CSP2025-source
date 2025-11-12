#include<bits/stdc++.h>
using namespace std;
int t,n;
struct aaa{
	int a,b,c;	
}a[10500];
struct spdt{
	int c,n,m,id;
}c[11451];
int bj(int x,int y,int z){
	if(x>y){
		if(x>z){
			return 1;
		}else{
			return 3;
		}
	}else if(y>z){
		return 2;
	}else{
		return 3;
	}
	
}
int bj1(int x,int y,int z){
	if(bj(x,y,z)==1){
		if(y>z)
			return 2;
		else 
			return 3;
	}else if(bj(x,y,z)==2){
		if(x>z)
			return 1;
		else
			return 3;
	}else{
		if(x>y)
			return 1;
		else
			return 2;
	}
	
}
bool cmp(spdt x,spdt y){
	return x.c>y.c;
}
int wy(int x,int y){
	if(y==1)
		return a[x].a;
	else if(y==2)
		return a[x].b;
	else
		return a[x].c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int cnt=0,k[5]={0,0,0,0,0};
		for(int j=1;j<=n;j++){
			cin>>a[j].a>>a[j].b>>a[j].c;
		}
		for(int j=1;j<=n;j++){
			int ls[3]={a[j].a,a[j].b,a[j].c};
			sort(ls,ls+3);
			c[j].c=ls[2]-ls[1];
			c[j].n=bj(a[j].a,a[j].b,a[j].c);
			c[j].m=bj1(a[j].a,a[j].b,a[j].c);
			c[j].id=j;
		}
		sort(c+1,c+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(k[c[j].n]<(n>>1)){
				k[c[j].n]++;
				cnt+=wy(c[j].id,c[j].n);
			}else{
				k[c[j].m]++;
				cnt+=wy(c[j].id,c[j].m);
			}
		}
		cout<<cnt<<endl;
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
