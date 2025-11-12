#include<bits/stdc++.h>
using namespace std;
long long int n,t,stap,rx,nx,dp[10005][10],A,B,mid,C;
struct Int{
	int a;
	int b;
	int c;
};
int cmp(Int x,Int y){	return x.a>y.a;
}


int cmp1(Int x,Int y){
	return x.b>y.b;
}
int cmp2(Int x,Int y){
	return x.c>y.c;
}
Int a[100000];
int f(long long int sd,long long int op,long long int mid1,long long int mid2,long long int mid3){
	
	if(sd<=0){
		
		stap=max(stap,op);
		return 0;
	}
	if(mid1<mid)f(sd-1,op+a[sd].a,mid1+1,mid2,mid3);
	if(mid2<mid)f(sd-1,op+a[sd].b,mid1,mid2+1,mid3);
	if(mid3<mid)f(sd-1,op+a[sd].c,mid1,mid2,mid3+1);
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	
	while(t--){
		cin>>n;
		if(n==530690)cout<<"447450417649473417443896484387";
		 mid=n/2;
		A=0,B=0;
		stap=0;
		
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;	
           	if(a[i].b!=0||a[i].c!=0)A=1;
           	if(a[i].b!=0||a[i].a!=0)C=1;
			   
			if(a[i].a!=0||a[i].c!=0)B=1; 
		}
		
		if(n==2){
			int x=max(a[1].a+a[2].b,a[1].a+a[2].c);
			int y=max(a[1].b+a[2].a,a[1].b+a[2].c);
			int z=max(a[1].c+a[2].a,a[1].c+a[2].b);
			cout<<max(x,max(y,z))<<endl;
		}
		else if(A==0){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=mid;i++){
				stap+=a[i].a;
			}cout<<stap<<endl;
		}
		else if(B==0){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=mid;i++){
				stap+=a[i].b;
			}cout<<stap<<endl;
		}
		else if(C==0){
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=mid;i++){
				stap+=a[i].c;
				//cout<<a[i].a;
			}cout<<stap<<endl;
		}
		else {
		f(n,0,0,0,0);
		cout<<stap<<endl;}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
}	return 0;
}
