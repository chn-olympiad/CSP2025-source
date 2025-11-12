#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector <int> b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0,p=0;
	string sr;getline(cin,sr);
	for(int i=0;i<sr.size();i++){
		if(isdigit(sr[i])){
			p++;
			a[p]=sr[i]-'0';
			
		}
		
	}
	sort(a+1,a+1+p,greater<int>());
	for(int i=1;i<=p;i++)cout<<a[i];
	
	return 0;
}
