#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[15][15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> t;
	int yy;
for(int i=1;i<=n;i++){//hang
	for(int j=1;j<=m;j++){//lie
		cin>>yy;
		t.push_back(yy);
	}
}
	int tmp=t[0];
	sort(t.begin(),t.end());
	int q=t.size();
	reverse(t.begin(),t.end());
	int i=1,j=1;
for(int k=0;k<q;k++){
	a[i][j]=t[k];
	if((i==n&&j%2==1)||(i==1&&j%2==0))j++;
	else if(j%2==0)i--;
	else i++;
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(a[i][j]==tmp){
			cout<<j<<" "<<i;
			return 0;
		}
	}
}
	return 0;
}
