#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e3+10;
int n,m;
pair<int,int>a[N];
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.first>y.first; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);	
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n*m+1,cmp);
	int r=1,c=1,dr=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].second==1){
			cout<<r<<" "<<c;
			return 0;
		}
		if(dr==1&&c==n)
			++r,dr=-dr;
		else if(dr==-1&&c==1)
			++r,dr=-dr;
		else
			c+=dr;
	}
	return 0;
}
