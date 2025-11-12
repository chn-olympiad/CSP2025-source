#include<bits/stdc++.h>

using namespace std;

const int N=15;
int n,m,a[N*N],mp[N][N],ch,ansx=0,ansy=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int x=1;x<=n*m;x++){
		cin>>a[x];
	}
	ch=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,b=0;
	for(int i=1;i<=n*m;i++){
		mp[x][y]=a[i];
		if(a[i]==ch){
			cout<<y<<" "<<x;
			return 0;
		}
		if(i%n==0){
			y++;
			if(x==1){
				b=0;
			}else{
				b=1;
			}
		}else{
			if(b==0){
				x++;
			}else{
				x--;
			}
		}
	}
	return 0;
}

/*
2 2
99 100 97 98
* 
2 2
98 99 100 97
*/
