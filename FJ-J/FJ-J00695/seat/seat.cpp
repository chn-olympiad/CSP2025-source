#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[1010];
int b[110][110];
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
	x=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int n1=1,m1=1;
	if(a[1]==x){
		cout<<"1 1";
		return 0;
	}
	b[1][1]=a[1];
	for(int i=1;i<=n*m-1;i++){
		if(m1%2!=0 and n1!=n){
			n1+=1;
		}
		else if(m1%2==0 and n1!=1){
			n1-=1;
		}
		else if(m1%2!=0 and n1==n){
			m1+=1;
		}
		else if(m1%2==0 and n1==1){
			m1+=1;
		}
		b[n1][m1]=a[i+1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==x){
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
