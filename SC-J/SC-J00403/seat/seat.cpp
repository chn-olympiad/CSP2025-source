#include<bits/stdc++.h>
using namespace std;
int a[1001];
int b[101];
bool cmp(int x,int y){
	if(x>y)
		return 1;
	return 0;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum,num=0,c,x=1,y=1;
	cin>>n>>m;
	sum=m*n;
	
	for(int i=1;i<=sum;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	c=a[1];
	if(sum==1){
		cout<<c;
		return 0;
	} 
	for(int i=100;i>=1;i--){
		if(b[i]==1){
			if(x%2==1){
				y+=1;
				if(y>n){
					x+=1;
					y=n;
				}
				if(i!=c)
					continue;	
			}
			if(x%2==0){
				y-=1;
				if(y<0){
					x+=1;
					y=1;
				}
				if(i!=c)
					continue;	
			}
			if(i==c)
				cout<<x<<" "<<y;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}