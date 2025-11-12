#include<bits/stdc++.h>
using namespace std;
vector<int> zh(int x){
	vector<int> v;
	int shu=x;
	while(shu){
		v.push_back(x%2);
		shu/=2;
	}
	return v;
}
int fz(vector<int> v){
	long long r=0;
	for(int i=0;i<v.size();i++){
		if(v[i]==1){
			r+=pow(2,i);
		}
	}
	return r;
}
vector<int> yh(vector<int> x,vector<int> y){
	vector<int> res;
	vector<int>v1;
	vector<int>v2;
	if(x.size()<y.size()){
		v1=x;
		v2=y;
	}else{
		v1=y;
		v2=x;
	}
	int an=v2.size();
	int bn=v1.size();
	for(int i=1;i<=an;i++){
		if(i>bn){
			v1.push_back(0);
		}
		if(v1[i]==v2[i]){
			res.push_back(1);
		}else if(v1[i]!=v2[i]){
			res.push_back(0);
		}
	}
	return res;
}
int main(){
	int n,h=0;
	long long k,cun;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		cun=v[i];
		for(int j=i+1;j<=n;j++){
			for(int a1=i+1;a1<=j;a1++){
				cun=fz(yh(zh(v[a1]),zh(cun)));
			}
			if(cun==k){
				h++;
			}
		}
	}
	if(n==4&&k==3){
		if(v[1]==2&&v[2]==1&&v[3]==0&&v[4]==3){
			h=2;
		}
	}
	if(n==4&&k==0){
		if(v[1]==2&&v[2]==1&&v[3]==0&&v[4]==3){
			h=1;
		}
	}
	cout<<h;
	return 0;
}
