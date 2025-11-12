#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[n*m],cr,t=0,c,r;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	cr=b[0];
	sort(b,b+(n*m),cmp);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[t]==cr){
				c=i;
				r=j;
			}
			t++;
		}
		i++;
		if(i<m){
			for(int j=n-1;j>=0;j--){
				if(b[t]==cr){
					c=i;
					r=j;
				}
				t++;
			}
		}
	}
	cout<<c+1<<" "<<r+1;
	return 0;
}
