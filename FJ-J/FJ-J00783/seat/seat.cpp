#include<bits/stdc++.h>
using namespace std;
short n,m,sr;
short s[114514];
short sn,ans1,ans2;
bool cmp(short a,short b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)s[i]=0;
	for(int i=0;i<n*m;i++)cin>>s[i];
	sr=s[0];
	sort(s,s+n*m,cmp);
	for(int i=n*m;i>=0;i--){
		if(s[i]==sr){
			sn=i+1;break;
		}
	}
	
	ans1=(sn-1)/n+1;
	if(ans1%2==0)
	ans2=n-((sn-1)%n+1)+1;
	else ans2=(sn-1)%n+1;
	
	cout<<ans1<<' '<<ans2; 
	return 0;
}
