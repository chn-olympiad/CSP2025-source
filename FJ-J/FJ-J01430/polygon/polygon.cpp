#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int s=0;
void dp(int xe,int ma,int t,int be){
	if(t>=3&&xe>ma*2){
		s=s+1;
		if(s>998244353){
			s%=998244353;
		}
	}
	if(t==a.size()){
		return ;
	}
	for(int i=be+1;i<a.size();i++){
		if(a[i]>ma){
			dp(xe+a[i],a[i],t+1,i);
		}
		else{
			dp(xe+a[i],ma,t+1,i);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	dp(0,0,0,-1);
	cout<<s;
	return 0;
}
