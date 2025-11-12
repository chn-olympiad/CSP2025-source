#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],r,ans1,ans2,s,cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int x=1,y=1,f=1;//f为1向下走，为2向上走
void dfs(){
	while(cnt<s){
		if(x!=1&&x!=n){
			if(f==1){
				x++;	
			}else{
				x--;
			}
		}else{
			if(f==1&&x==n){
				y++,f=2;	
			}else if(f==2&&x==1){
				y++,f=1;
			}else{
				if(f==1){
					x++;	
				}else{
					x--;
				}
			} 
		}
		cnt++;
	}	
	cout<<y<<" "<<x;	 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			r=a[i];
		}
	}
	int len=n*m;
	sort(a+1,a+1+len,cmp);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			s=i;
		}
	}
	dfs();
	return 0;
} 
/*
4 4
5 3 4 2 6 7 8 9 10 11 12 13 14 15 16 17
*/
