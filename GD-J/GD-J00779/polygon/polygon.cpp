#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
bool check(vector<int> vv){
	if(vv.size()>=3){
		int cnt=0,max_num=INT_MIN;
		for(int i=0;i<vv.size();++i){
			cnt+=a[vv[i]];
			//cout<<' '<<cnt<<'\n'; 
			max_num=max(max_num,a[vv[i]]);
		}
		if(cnt>(max_num*2+1)) return true;
		return false;
	}
	return false;
}
void f(vector<int> v,int d){
	for(int i=0;i<n;++i){
		bool is_idx_exi=0;
		if(!v.empty()){
			if(find(v.begin(),v.end(),i)!=v.end()){
				is_idx_exi=1;
			}
		}
		if(!is_idx_exi){
			v.push_back(i);
			if(d>=3){
				if(check(v)) ans++;
			}
			f(v,d+1);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	vector<int> thisisv;
	f(thisisv,1);
	cout<<ans;
	return 0;
}
