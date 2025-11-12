#include<bits/stdc++.h>
using namespace std;
struct Node{
	int s,id;
}a[1010];
int n,m;
bool cmp(Node a,Node b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1){
			if(((i-1)/n%2==0))cout<<(i-1)/n+1<<" "<<i-(i-1)/n*n;
			else cout<<(i-1)/n+1<<" "<<n-i+(i-1)/n*n+1;
			break;
		}
	return 0;
}
