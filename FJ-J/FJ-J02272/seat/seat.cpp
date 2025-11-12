#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],r,w,u,q;
int cmp(int k,int l){
	return k>l;
}
void pdd(){
	while(w>n){
		w=w-n;
		u++;
	}
	q=w;
	if(u%2==1&&q>0)
		cout<<u+1<<" "<<n-q+1;
	if(u%2==0&&q>0)
		cout<<u+1<<" "<<q;
	if(u%2==0&&q==0)
		cout<<u<<" "<<n;
	if(u%2==1&&q==0)
		cout<<u<<" "<<1;
	return ;
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
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r){
			w=i;
			break;
		}
	}
	pdd();
	return 0;
}
