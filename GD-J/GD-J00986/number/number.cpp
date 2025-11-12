#include<bits/stdc++.h>
using namespace std;
string a;
vector<int> num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a;
	for(unsigned int i=0;i<a.size();i++){
		if(a[i]>='0' and a[i]<='9'){
			num.push_back(a[i]-int('0'));
		}
	}
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i];
	}
	fclose(stdin);
	return 0;
} 
