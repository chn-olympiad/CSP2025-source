#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt;
int a[100005];
int s[10005][10005];
int cmp(int l,int r){
	return r<l;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin>>n>>m>>t;
	int l=n*m;
	for(int i=1;i<l;i++){
		cin>>a[i];
	}
	a[l]=t;
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l+1;i++){
		if(a[i]==t){
			cnt=i;
			continue;
		}
	}
	int x=n*2-1,y=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j==1){
				s[i][j]=i;
				if(s[i][j]==cnt){
					cout<<j<<" "<<i;
					return 0;
				}
			}else if(j%2==0){
				s[i][j]=x+s[i][j-1];
				if(s[i][j]==cnt){
					cout<<j<<" "<<i;
					return 0;
				}
			}else if(j%2==1){
				s[i][j]=y+s[i][j-1];
				if(s[i][j]==cnt){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		x-=2;
		y+=2;
	}
	return 0;
}
