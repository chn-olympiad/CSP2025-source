#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1010],vis[1010][1001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n+1,cmp);
	int x=1,y=1,re=0;
	for(int i=2;i<=n*m;i++){
		if(re==0){
			x++;
		}else{
			x--;
		}	

		if(a[i]==k)cout<<y<<" "<<x;
		if(i%n==0){
			re=1;
			y++;
		}
		
		
	}

	return 0;
} 
