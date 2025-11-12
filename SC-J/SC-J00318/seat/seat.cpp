#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],x,y,cnt,b;
bool cmp(int l,int r){return l>r;};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	b=a[1];
	sort(a+1,a+1+n*m,cmp);
	x=0,y=1,cnt=1;
	for(int i=1;1;i++){
		if(x==n&&cnt!=-1) y++,cnt=-1;
		else if(x==1&&cnt!=1) y++,cnt=1;
		else x+=cnt;
		if(a[i]==b){
			cout<<y<<" "<<x;
			return 0;
		}
	} 
	return 0;
}
