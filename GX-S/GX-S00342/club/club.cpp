#include<bits/stdc++.h>
using namespace std;
int t,a[1000000][3],n,b[3],l,d;
bool c[1000000][3];
void f(int x){
	if(x>=n){
		if(d<l){
			d=l;
		}
		return ;
	}
	for(int j=0;j<3;j++){
		if(c[x][j]==0&&b[j]+1<=n/2){
			c[x][j]=1;
			b[j]++;
			l+=a[x][j];
			f(x+1);
			l-=a[x][j];
			c[x][j]=0;
			b[j]--;
		}
	}
}
int main(){
	stdin(club.in,'w',stdin);
	stdout(club.out,'r',stdout);
	cin>>t;
	int g[t],y=0;
	for(int i=0;i<t;i++){
		cin>>n;
		d=0;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			}
		f(0);
		g[y++]=d;
	}
	for(int i=0;i<t;i++)cout<<g[i]<<endl;
	return 0;
}

