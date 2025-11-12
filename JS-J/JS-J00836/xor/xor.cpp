#include<bits/stdc++.h>
using namespace std;
vector<long long>a,yih;
vector<int> ls;
vector<int> rs;
//vector<long long> jieg;
int n;
long long k,nums;
void yi(){
	yih.push_back(a[0]);
	for(int i=1;i<n;i++){
		yih.push_back(yih[i-1]^a[i]);
	}
}
long long yihuh(int l,int r){
	return yih[r]^yih[l];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>nums;
		a.push_back(nums);
	}
	yi();
	//cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			long long de;
			if(i==0) de = yih[j];
			else de = yihuh(i-1,j);
			if(de==k){
				ls.push_back(i);
				rs.push_back(j);
				//jieg.push_back(de);
			}
		}
	}
	int jz = ls.size();
	vector<int> fla;
	for(int i=0;i<n;i++) fla.push_back(0);
	for(int i=0;i<jz;i++){
		//cout<<ls[i]<<' '<<rs[i]<<endl;
		for(int j=ls[i];j<=rs[i];j++)
			fla[j]++;
	}
	int maxc=0;
	bool flag=1;
	for(int i=0;i<n;i++){
		maxc = max(maxc,fla[i]);
		//cout<<fla[i]<<' ';
		if((i>0&&fla[i]!=fla[i-1])||
		fla[i]==1)flag=0;
	}
	//cout<<endl<<maxc<<endl;
	long long ans=jz+1-maxc;
	if(flag) ans--;
	cout<<ans;
	return 0;
}
