#include<bits/stdc++.h>
using namespace std;
long long x,p,n,m,j,i,k,l,b[1000000],z,t,r,y,a[1000000],v[1000000];
string s;
bool pp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		for (long long j=1;j<=m;j++){
			y++;
			cin>>a[y];
		}
	}
	k=a[1];
	sort(a+1,a+y+1,pp);
	x=0;
	p=0;//往下 
	i=0;//列 
	j=1;//行 
	while(x!=y){
		x++;
		if(x%n==1&&p==1){
			p=0;//往上 
			i++;
			j=n;
		}
		else if(x%n==1&&p==0){
			p=1;
			i++;
			j=1;
		}
		if(a[x]==k){
			cout<<i<<" "<<j;
			break;
		}
		if(p==1){
			j++;
		}
		if(p==0)j--;
		
		
	}
	
} 
