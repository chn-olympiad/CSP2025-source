#include<bits/stdc++.h>
using namespace std;
int n;
vector <int> b;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	cin>>a;
	n=a.length();
	for(int i=0;i<n;i++)if(a[i]>=48 and a[i]<=57)b.push_back(a[i]);
	sort(b.begin(),b.end());
	n=b.size();
	for(int i=n-1;i>=0;i--){
		cout<<char(b[i]);	
	}
	return 0;
} 
