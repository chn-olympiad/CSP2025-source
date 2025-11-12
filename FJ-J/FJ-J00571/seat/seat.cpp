#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int v;
		cin>>v;
		a.push_back(v);
	}
	int k=a[0];
	sort(a.begin(),a.end(),cmp);
	int i=0;
	while(a[i]!=k){
		i++;
	}
	bool k1=true,k2=false;
	int c=1,r=1;
	for(;i>0;i--){
		if((r==n||r==1)&&k2){
			k1=!k1;
			c++;
			k2=false;
		}
		else{
			if(k1) r++;
			else r--;
			k2=true;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

