#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,m,x,y,s[1000],t,s1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	s1=s[1];
	sort(s+1,s+n*m+1,cmp);
	x=1,y=1;
	while(y<=n){
		while(x<=n){
			t++;
			if(s[t]==s1){
				printf("%d %d",y,x);
				return 0;
			}
			x++;
		}
		y++;
		x--;
		while(x>=1){
			t++;
			if(s[t]==s1){
				printf("%d %d",y,x);
				return 0;
			}
			x--;
		}
		y++;
		x++;
	}
	return 0;
} 
