#include<bits/stdc++.h>
using namespace std;

int n,m,s,pos;
int a[100005];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==s) pos=i;
	cout<<pos/n+(pos%n!=0?1:0)<<" ";
	int tmp=pos%n;
	if(tmp==0&&pos/n+(pos%n!=0?1:0)&1) cout<<n;
	else if(tmp==0) cout<<1;
	else if(pos/n+(pos%n!=0?1:0)&1) cout<<tmp;
	else cout<<n-tmp+1; 
}
