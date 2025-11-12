#include<bits/stdc++.h>
using namespace std;
void f(vector<int> &v){
	sort(v.begin(),v.end());
	int x=v[0];
	for(int i=1;i<v.size();i++){
		if(v[i]==x) v[i]=INT_MAX;
		else x=v[i];
	}
	sort(v.begin(),v.end());
	while(v.back()==INT_MAX) v.pop_back();
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,c,x=0,t=0;
	vector<int>v;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&c);
		for(int j=0;j<v.size();j++){
			v[j]=v[j]^c;
		}
		v.push_back(c);
		f(v);
		for(int j=0;j<v.size();j++){
			if(v[j]==k){
				v.clear();
				t++;
			} 
		}
	}
	cout<<t;
	return 0;
}