#include<bits/stdc++.h>
using namespace std;
#define int long long
//priority_queue<int,vector<int>,greater<int>>
const int N=110;
int n,m,pos;
struct Node{
	int num;
	bool flag;
}jpos[N];
bool cmp(Node a,Node b){
	return a.num>b.num;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>jpos[0].num;
	jpos[0].flag=true;
	for(int i=1;i<n*m;i++)
		cin>>jpos[i].num;
	sort(jpos,jpos+n*m,cmp);
	for(;pos<n*m;pos++)
		if(jpos[pos].flag)
			break;
	cout<<pos/n+1<<' ';
	if((pos/n+1)%2){
		pos++;
		if(pos%n==0) cout<<n;
		else cout<<pos%n;
	}else{
		pos++;
		if(pos%n==0) cout<<1;
		else cout<<n-pos%n+1;
	}
}
