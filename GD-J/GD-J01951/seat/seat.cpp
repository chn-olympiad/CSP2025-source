#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int r;
int n,m;
int c[110];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>c[i];
		if(i==0) r=c[i];
	}
	sort(c,c+n*m,cmp);
	
	int cnt=0;
	for(int i=0;i<n*m;i++) 
		if(c[i]==r) cnt=i+1;
		
		int i=1;
	while(i*n<cnt){
		i++;
	}
	int j=0;
	int flag=cnt-(i-1)*n;
	if(i%2) j=flag;
	else j=n-flag+1;
	cout<<i<<' '<<j<<endl;
	return 0;
} 
