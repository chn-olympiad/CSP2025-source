#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,fen;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	fen=a[1];
	sort(a+1,a+m*n+1,cmp);
	int wei;
	for(int i=1;i<=m*n;i++){
		if(a[i]==fen){
			wei=i;
			break;
		}
	}
	int q=0,ans1,ans2,f=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			q++;
			if(q==wei){
				ans1=i;
				ans2=j;
				f=1;
				break;
			}
		}
		if(f)	break;
		i++;
		for(int j=n;j>=1;j--){
			q++;
			if(q==wei){
				ans1=i;
				ans2=j;
				break;
			}
		}
		if(f)	break;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}