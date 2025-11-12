#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct node{
	int v,id;
}a[maxn];
bool cmp(node x,node y){
	return x.v>y.v;
}
int n,m,k,nowh,nowl;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].v,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1)k=i;
	}
	nowh=nowl=1;
	if(k==1){
		cout<<1<<' '<<1;
		return 0; 
	}
	for(int i=2;i<=n*m;i++){
		if(nowl==1&&nowh%2==0){
			nowh++; 
		} else if(nowl==n&&nowh%2==1){
			nowh++;
		}else{
			if(nowh%2==1)nowl++;
			else nowl--;
		}
		if(i==k)break;
	}
	cout<<nowh<<' '<<nowl;
}
