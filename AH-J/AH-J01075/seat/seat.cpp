#include<bits/stdc++.h>
using namespace std;
long long a[100][100],b[10000],fs;
long long m,n;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>fs;
			b[i]=fs;
		}else{
			cin>>b[i];
		}
	}sort(b+1,b+1+n*m,cmp);
	long long x=1,y=1,f=1;
	long long t=0;
	while(t<=n*m){
		t++;
		if(b[t]==fs){
			cout<<y<<" "<<x;
			break;
		}
		if(f==1){
			if(x==n) y++,f=2;
			else x++;
		}else if(f==2){
			if(x==1) y++,f=1;
			else x--;
		}
	}
	return 0;
}
