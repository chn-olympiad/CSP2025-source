#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
int n,m;
const int N=105;
PII a[N];
bool cmp(PII a,PII b){
	return a.first>b.first;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int loc;
	for(int i=1;i<=n*m;i++)
		if(a[i].second==1){
			loc=i;
			break;
		}
	int l=(loc+n-1)/n;
	int h=loc-(l-1)*n;
	if(l%2==0){
		cout<<l<<" "<<(n-h+1);
	}else{
		cout<<l<<" "<<h;
	}
	return 0;
}
