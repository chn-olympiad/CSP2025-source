#include<bits/stdc++.h>
using namespace std;
int n;
string a;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			v.push_back((int)a[i]-48);
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if(v[0]==0||v.size()==0){
		cout<<0;
		return 0;
	}else{
		for(int i=0;i<v.size();i++){
			cout<<v[i];
		}
	}
}

