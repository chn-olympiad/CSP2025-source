#include<bits/stdc++.h>
using namespace std;
string replace(string a,string b,int i){
	int end=i+b.size(),bi=i;
	for(;i<end;i++){
		a[i]=b[i-bi];
	}
	return a;
}
bool cmp(string a,string b,int k){
	for(int i=0;i<k;i++){
		if(a[i]!=b[i])return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<string>str(200001);
	vector<string>strs(200001);
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		strs[i]=b;
		str[i]=a;
	} 
	for(int i=0;i<q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<n;i++){
			int k=0;
			while(a.find(str[i],k)!=string::npos){
				if(!cmp(a,b,a.find(str[i],k)))break;
				string test=replace(a,strs[i],a.find(str[i],k));
				if(test==b)ans++;
				k=a.find(str[i],k)+1;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
