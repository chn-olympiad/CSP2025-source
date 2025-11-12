#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	vector<char>c;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			c.push_back(a[i]);
		}
	}
	sort(c.begin(),c.end());
	for(int i=c.size()-1;i>=0;i--){
		if(i==c.size()-1&&c[i]=='0'){
			cout<<0;
			i=-1;
		}else{
			cout<<c[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
