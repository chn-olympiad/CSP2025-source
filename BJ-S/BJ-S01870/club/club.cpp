#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][0]=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++)if(a[i][0]==a[i][j])a[i][4]=j;
		}
		int x=n/2;
		int cnt[5]={};
		for(int i=1;i<=n;i++)cnt[a[i][4]]++;
		int h=0,c[100005]={},k=0,b=max(max(cnt[1],cnt[2]),cnt[3])-x;
		int sum=0;
		for(int i=1;i<=3;i++)if(cnt[i]>x)h=i;
		if(h>0){
			for(int i=1;i<=n;i++){
				if(a[i][4]==h){
					c[++k]=a[i][h]-max(a[i][h%3+1],a[i][(h+1)%3+1]);
				}
			}
			sort(c+1,c+1+k);
			for(int i=1;i<=b;i++)sum-=c[i];
		}
		for(int i=1;i<=n;i++)sum+=a[i][0];
		cout<<sum<<'\n';
	}
	return 0;
}
