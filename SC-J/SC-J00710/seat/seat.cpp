#include<bits/stdc++.h>
using namespace std;
int n,m;
struct p{
	int chen;
	int r;
}c[110];
bool cmp(p a,p b){
	return a.chen>b.chen;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c[1].r=1;
	for(int i=1;i<=n*m;i++){
		cin>>c[i].chen;
	}
	sort(c+1,c+n*m+1,cmp);
	int a=1,b=1;
	int fang=0;
	for(int i=1;i<=n*m;i++){
		if(c[i].r==1){
			cout<<a<<" "<<b;
			return 0;
		}
		if(fang==0){
			if(b<m){
				b++;
			}else{
				fang=1;
				a++;
			}
		}else if(fang==1){
			if(b>1){
				b--;
			}else{
				fang=0;
				a++;
			}
		}

	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/