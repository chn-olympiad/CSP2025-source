#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1010];
int v;
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
	int u=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==u){
			v=i;
			break;
		}
	}
	int c=1,x=0,l=0;
	for(int i=1;i<=v;i++){
		if(l==0){
			x++;
			if(x==n+1){
				x=n;
				c++;
				l=1;
				continue;
			}
		}
		if(l==1){
			x--;
			if(x==0){
				x=1;
				c++;
				l=0;
			} 
		}
	}
	cout<<c<<" "<<x;
	return 0;
} 