#include<bits/stdc++.h>
using namespace std;
int a[105],s[15][15];
cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,now;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			now=i;
			break;
		}
	}
	int h=1,l=1;
	for(int i=1;i<now;i++){
		s[l][h]++;
		if(h+1<=n&&s[l][h+1]==0)h++;
		else if(l+1<=m&&s[l+1][h]==0)l++;
		else if(h-1>0&&s[l][h-1]==0)h--;
		else if(l-1>0&&s[l-1][h]==0)l--;
	}
	cout<<l<<" "<<h;
	return 0;
} 