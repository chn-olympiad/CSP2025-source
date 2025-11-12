#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("replace.in","i",stdin);
	freopen("replace.out","o",stdout);
	int n=0,q=0,m=0;
	cin>>n>>q;
	vector<string>a;
	vector<string>b;
	for(int i=0;i<n;i++){
		string s1;
		string s2;
		cin>>s1>>s2;
		a.push_back(s1);
		b.push_back(s2);
	}
	for(int i=0;i<q;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(a[i]==s1 && b[i]==s2){
			m++;
		}
		
		
		
		
		cout<<m;
	}
	
	
	
	
	return 0;
}
