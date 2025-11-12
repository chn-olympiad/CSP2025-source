#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,k,ans;
int a[500005],b[500005];
vector<int> T[1500000];
vector<pair<int,int>> v;
bool cmp(pii num1,pii num2){
	if(num1.first==num2.first) return num1.second<num2.second;
	return num1.first<num2.first;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		T[b[i]].push_back(i);
		if(a[i]==k){
			pair<int,int> tttt;
			tttt.first=i;
			tttt.second=i;
			v.push_back(tttt);
		}	// 只有一个数字时的特判
	}
	for(int i=1;i<=n;i++){
		if(!T[a[i-1]^k].empty()){
			for(int j=0;j<(int)T[a[i-1]^k].size();j++){
				if(T[a[i-1]^k][j]>i){
					pair<int,int>tttt;
					tttt.first=i;
					tttt.second=T[a[i-1]^k][j];
					v.push_back(tttt);
				}
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	ans=v.size();
	for(int i=1;i<(int)v.size();i++){
		if(v[i].first>v[i-1].second){
			ans--;
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<(int)v.size();i++)
		cout<<v[i].first<<" "<<v[i].second<<endl;
	return 0;
}
