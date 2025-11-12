#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int c=a[1];
	sort(a+1,a+1+n*m,cmp);
	int s;
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			s=i;
			break;
		}
	}
	int x=1,y=0;
	for(int i=1;i<=s;i++){
		if(x%2==1){
			if(y<n)y++;
			else x++;
		}else{
			if(y>1)y--;
			else x++;
		}	
	}
	cout<<x<<' '<<y;
	return 0;
}
