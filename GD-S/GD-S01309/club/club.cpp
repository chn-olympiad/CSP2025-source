#include <bits/stdc++.h>
using namespace std;
int t,n,an,at,bt,ct;
void sol(){
	priority_queue<int> a,b,c;
	cin>>n; an=0; at=0; bt=0; ct=0;
	for(int i=1,j,k,l;i<=n;i++){
		cin>>j>>k>>l;
		an+=max(j,max(k,l));
		if(j>=k&&j>=l){
			a.push(max(k,l)-j);
			at++;
		}else{
			if(k>=j&&k>=l){
				bt++;
				b.push(max(j,l)-k);
			}else{
				ct++;
				c.push(max(j,k)-l);
			}
		}
		while(at>n/2){
			an+=a.top();
			at--; a.pop();
		}
		while(bt>n/2){
			an+=b.top();
			bt--; b.pop();
		}
		while(ct>n/2){
			an+=c.top();
			ct--; c.pop();
		}
	}
	cout<<an<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int it=1;it<=t;it++){
		sol();
	}
	return 0;
}
