#include<bits/stdc++.h>
using namespace std;
struct Node{
	int ind,x,y,scr;
}a[105];
bool cmp(Node a,Node b){
	return a.scr>b.scr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,now=0;
	bool rev=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].scr;
		a[i].ind = i;
	}
	sort(a,a+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[now].x = i;
			if(rev){
				a[now].y = n-j+1;
			}else{
				a[now].y = j;
			}
//			cout<<a[now].x<<' '<<a[now].y<<endl;
			now++;
			
		}
		rev = !rev;
	}
	for(int i=0;i<n*m;i++){
		if(a[i].ind == 0){
			cout<<a[i].x<<' '<<a[i].y;
			return 0;
		}
	}
	
}