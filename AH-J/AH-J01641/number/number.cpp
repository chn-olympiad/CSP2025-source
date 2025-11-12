#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
	vector <long long>num;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string in;
	cin>>in;
	for(int i=0;i<in.end()-in.begin();i++){
		if(in[i]-'0'>=0 && in[i]-'0'<=9){
			num.push_back(in[i]-'0');
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.end()-num.begin();i++){
		cout<<num[i];
	}
	return 0;
}
