#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<int> s;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s.push_back(a[i]-='0');
			
		}
	}
	sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;i--){
		cout<<s[i];
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 