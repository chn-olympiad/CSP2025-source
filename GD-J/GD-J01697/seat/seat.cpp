#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct node{
	int x;
	int f=0;
}a[1010];
int read(){
	int cnt=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) cnt=cnt*10+ch-'0';
	return cnt*f;
}
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	time_t start=clock();
	n=read(),m=read();
	a[1].f=1;
	ll k=n*m;
	for(int i=1;i<=k;i++){
		a[i].x=read();
	}
	sort(a+1,a+k+1,cmp);
	int ans=0,tot=0,cnt=1;
	for(int i=1;i<=k;i++){
		tot++;
		if(a[i].f==1){
			ans=i;
			break;
		}
		if(tot==n) tot=0,cnt++;
	}
	if(cnt%2!=0) cout<<cnt<<" "<<ans-(cnt-1)*n;
	else cout<<cnt<<" "<<n-(ans-(cnt-1)*n)+1;
//	time_t duration=clock()-start;
//	cout<<'\n'<<duration<<"ms";
	return 0;
}
