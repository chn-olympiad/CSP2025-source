#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[110],x=1,y=1;
bool bx=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)sum=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	//cout<<sum<<endl;
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&bx==0){
			y++;
			bx=1;
			continue;
		}
		if(x==1&&bx==1){
			y++;
			bx=0;
			continue;
		}
		if(!bx)x++;
		else x--;
	}
	return 0;
}
