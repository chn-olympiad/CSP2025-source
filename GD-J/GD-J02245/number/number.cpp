#include<bits/stdc++.h>
using namespace std;
string n;
vector<int> v;
int k;
bool cmp(int a,int b){
	if(a>b) return 1;
	return 0;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	n=' '+n;
	for(int i=1;i<=n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			v.push_back(n[i]-'0');
			k++;
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(auto e:v){
		cout<<e;
	}
	return 0;
} 
