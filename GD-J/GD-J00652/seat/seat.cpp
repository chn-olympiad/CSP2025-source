#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,int>> mp;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i=1,j=1,cnt=1;
	while(j<=m){
		mp[cnt]={i,j};
		cnt++;
		if (j%2==1) i++;
		else i--;
		if (i==0){
			j++;
			i=1;
		}
		else if (i==n+1){
			j++;
			i=n;
		}
	}
	for (i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1],q;
	sort(a+1,a+1+n*m,cmp);
	for (i=1;i<=n*m;i++){
		if (a[i]==p){
			q=i;
			break;
		}
	}
	cout<<mp[q].second<<' '<<mp[q].first;
	return 0;
}
