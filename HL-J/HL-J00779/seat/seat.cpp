#include<bits/stdc++.h>
using namespace std;
int n,m,a[110]={},z,x,y,f=1,j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	} 
	z=a[0];
	sort(a,a+(m*n),cmp);
	while(x<n&&y<m){
		if(a[j]==z){
			cout<<y+1<<' '<<x+1;
			return 0;
		}
		if(x==0 && f==-1){
			j++;
			y++;
			f=1;
			continue;
		}
		if(x==n-1 && f==1){
			j++;
			y++;
			f=-1;
			continue;
		}
		j++;
		x+=f;
	}
	return 0;
}
