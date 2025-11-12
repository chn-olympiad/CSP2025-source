#include<bits/stdc++.h>
using namespace std;
string a;
vector<int>k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(isdigit(a[i])){
			k.push_back(a[i]-'0');
		}
	}
	sort(k.begin(),k.end(),cmp);
	for(int i=0;i<k.size();i++)cout<<k[i];
	return 0;
} 
