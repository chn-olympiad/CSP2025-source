#include<bits/stdc++.h>
using namespace std;
int m,n,a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mn=m*n;
	for(int i=0;i<mn;i++){
		cin>>a[i];
	}
	int xiaor=a[0],tc;
	sort(a,a+mn);
	for(int i=mn-1;i>=0;i--){
		if(a[i]==xiaor){
			tc=mn-i;
			break;
		}
	}
	int l=(tc-1)/n;
	l++;
	cout<<l<<" ";
	int yq=(l-1)*n;
	int h=tc-yq;
	if(l%2==1){
		cout<<h;
		return 0;
	}
	h=n-h+1;
	cout<<h;
	return 0;
} 
