#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	vector<int>a;
	int k=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back((int)s[i]-48);k++;
		}
	} 
	sort(a.begin(),a.end());
	for(int i=k-1;i>=0;i--)cout<<a[i];
	return 0;	
} 
