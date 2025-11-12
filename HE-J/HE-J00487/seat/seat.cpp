#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],gd,id;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	
	gd=a[1];
	sort(a+1,a+1+n*m,cmp); //grades from high to low
	
	int i=1,j=1,cnt=1;
	while(cnt<=n*m){
		if(a[cnt]==gd) break;
		if(i<=n && (j%2)==1) i++;
		else if((j%2)==0 && i>=1) i--;
		if(i==n+1 || i==0){
			j++;
			if(i==n+1) i--;
			else if(i==0) i++;
		}
		cnt++;
	}
	cout<<j<<" "<<i; //cout lie then hang
	
	return 0;
}
