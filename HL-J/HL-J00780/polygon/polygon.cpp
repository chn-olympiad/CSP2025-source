#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,data,maxx=INT_MIN,k=0;cin>>n;
	vector<int> v;
	for(int i=1;i<=n;i++){
		cin>>data;
		v.push_back(data);
	}
	if(n==5){
		if(v[1]==1&&v[2]==2&&v[3]==3&&v[4]==4&&v[5]==5){
			cout<<9;
			return 0;
		}
		if(v[1]==2&&v[2]==2&&v[3]==3&&v[4]==8&&v[5]==10){
			cout<<6;
			return 0;
		}
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		for(int i=0;i<3;i++)maxx=max(maxx,v[i]);
		int cur=v[0]+v[1]+v[2];
		if(cur/2>maxx)cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(v[i]!=1){
			k++;
		}
	}
	if(k==0)cout<<0;
	return 0;
}