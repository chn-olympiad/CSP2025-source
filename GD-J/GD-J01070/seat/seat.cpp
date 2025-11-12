#include<bits/stdc++.h>
using namespace std;

int n,m,h=1,l=1,t,head;
int a[10086];
int b[1086][1086];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	memset(b,-1,sizeof(b));
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t = a[1];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j] = 0;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i] == t){
			cout<<l<<' '<<h;
			return 0;
		}
		b[h][l] = a[i];
		if(h-1 < 1 and head == 1){
			l++,head=0;
			continue;
		}
		else if(h+1>n and head == 0){
			l++,head=1;
			continue;
		}
		if(head) h--;
		else h++;
	}
	return 0;
} 
