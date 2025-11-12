#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	vector<int>P(n*m);
	int a;cin>>a;P[0]=a;
	for(int i=1;i<n*m;i++)cin>>P[i];
	sort(P.begin(),P.end(),cmp);
	int pos=-1;
	for(int i=0;i<n*m;i++)if(P[i]==a)pos=i+1;
	int ans1=1;
	while(pos>n){
		pos-=n;ans1++;
	}
	if(ans1%2==0){
		cout<<ans1<<" "<<n-pos+1;
	}
	if(ans1%2!=0){
		cout<<ans1<<" "<<pos;
	}
	return 0;
}