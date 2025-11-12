#include<bits/stdc++.h>
using namespace std;
int n,m,k,dx=1,dy=1,f=0;
int a[17][17],s[1001];
int x[3]={1,0,-1};
int y[3]={0,1,0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int k=s[1];
	sort(s+1,s+1+n*m,cmp);
	a[1][1]=s[1];
	if(m==1){
		for(int i=1;i<=n*m;i++){
			if(s[i]==k){
				cout<<1<<" "<<i;
				return 0;
			}
		}
	}
	if(n==1){
		for(int i=1;i<=n*m;i++){
			if(s[i]==k){
				cout<<i<<" "<<1;
				return 0;
			}
		}
	}
	for(int i=2;i<=n*m;i++){
		if(f==0){
			if(dx+1>n){
				f=1;
				a[dx][dy+1]=s[i];
				dy+=1;
			}else{
				a[dx+1][dy]=s[i];
				dx+=1;
			}
		}
		else if(f==1){
			if(dx==m){
				a[dx-1][dy]=s[i];
				dx-=1;
				f=2;
			}else if(dx==1){
				a[dx+1][dy]=s[i];
				dx+=1;
				f=0;
			}
		}
		else if(f==2){
			if(dx-1<1){
				f=1;
				a[dx][dy+1]=s[i];
				dy+=1;
			}else{
				a[dx-1][dy]=s[i];
				dx-=1;
			}
		}
		if(s[i]==k){
			cout<<dy<<" "<<dx<<endl;
			return 0;
		}
	}
	return 0;
}
