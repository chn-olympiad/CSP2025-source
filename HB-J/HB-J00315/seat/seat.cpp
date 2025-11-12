#include <bits/stdc++.h>
using namespace std;
int n,m,a[200],r,s,ans,cnt,w,v;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			s=i;
			break;
		}
	}
	ans=s/(2*n);
	cnt=s%(2*n);
	if(cnt==0){
		w=2*ans;
		v=1;
	}
	else if(cnt<=n){
		w=2*ans+1;
		v=cnt;
	}
	else if(cnt>n){
		w=2*ans+2;
		v=2*n-cnt+1;
	}
	cout<<w<<" "<<v;
	return 0;
}
