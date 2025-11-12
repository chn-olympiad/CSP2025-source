#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct PAIR{
	int f,s;
	bool operator== (PAIR o) const{
		if(this->s>=o.f){
			return true;
		}else return false;
	}
};

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	vector<int> vec(n+1);
	vector<PAIR> que;
	for(int i=1;i<=n;i++){
		cin>>vec[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int temp=vec[i];
			if(i==j&&vec[i]==k){
				que.push_back({i,j});
				continue;
			}
			for(int k=i+1;k<=j;k++){
				temp^=vec[k];
			}
			if(temp==k){
				que.push_back({i,j});
			}
		}
	}
	auto newend=unique(que.begin(),que.end());
	que.erase(newend,que.end());
	cout<<que.size();
//	cout<<endl;
//	for(auto a:que){
//		cout<<a.f<<' '<<a.s<<endl;
//	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
