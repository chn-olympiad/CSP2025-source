#include<bits/stdc++.h>
using namespace std;
const int N=110;
struct Node{
	int d,sc;
}b[N];
int n,m,k,ans1,ans2;
bool cmp(Node a,Node b){
	return a.sc>b.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].sc;
		b[i].d=i;
	}
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(b[i].d==1){
			k=i;
			break;
		}
	}
	ans1=(k-1)/n+1;
	if(ans1%2==1) ans2=k-(ans1-1)*n;
	else ans2=n-k+(ans1-1)*n+1;
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
