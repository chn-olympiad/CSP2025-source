#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],num=0,l=0,h=1;
bool f=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int tot=n*m;
	for(int i=1;i<=tot;i++)cin>>a[i];
	int me=a[1];
	sort(a+1,a+1+tot);
	for(int i=tot;i>0;i--){
		if(!f) l++;
		else l--;
		if(l==0){
		h++;f=false;	
		l=1;
		} 
		if(l==n+1){
			h++;f=true;
			l=n;
		} 
		if(a[i]==me){
			cout<<h<<' '<<l;
			return 0;
		} 
	}
	return 0;
} 
