#include<bits/stdc++.h>
using namespace std;
int n,p;
int x[10000];
int maxn,ans;
int a,b,c,d,e,f,g,h;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		maxn=max(x[1],x[0]);
		maxn=max(x[2],maxn);
		ans=x[1]+x[2]+x[0];
		if(ans>maxn*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		//3
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n-2;j++){
				maxn=max(x[j],x[j+1]);
				maxn=max(x[i],maxn);
				ans=x[i]+x[j]+x[j+1];
				if(ans>maxn*2){
					p++;
				}
				
			}
		}
		
		//4
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n-3;j++){
				a=max(x[j],x[j+1]);
				b=max(x[j+2],x[i]);
				maxn=max(a,b);
				ans=x[i]+x[j]+x[j+1]+x[j+2];
				if(ans>maxn*2){
					p++;
				}
				
			}
		}
		
		//5
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n-4;j++){
				a=max(x[j],x[j+1]);
				b=max(x[j+2],x[i]);
				c=max(a,x[j+3]);
				maxn=max(c,b);
				ans=x[i]+x[j]+x[j+1]+x[j+2]+x[j+3];
				if(ans>maxn*2){
					p++;
				}
				
			}
		}
		
		
		
		//6
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n-5;j++){
				a=max(x[j],x[j+1]);
				b=max(x[j+2],x[i]);
				c=max(x[j+4],x[j+3]);
				d=max(a,b);
				maxn=max(c,d);
				ans=x[i]+x[j]+x[j+1]+x[j+2]+x[j+3]+x[j+4];
				if(ans>maxn*2){
					p++;
				}
				
			}
		}
		
		
		
		cout<<p;
		
		
	}


	return 0;
}
