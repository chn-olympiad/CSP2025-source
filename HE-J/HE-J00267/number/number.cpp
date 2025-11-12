#include<bits/stdc++.h>
using namespace std;
string b;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int len_b=b.size();
	for(int i=0;i<len_b;i++){
		if(b[i]>='0'&&b[i]<='9'){
			a.push_back(b[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	int len_a=a.size();
	if(a[len_a-1]==0){
		cout<<0;
		return 0;
	}else if(len_a==1){
		cout<<a[0];
		return 0;
	}
	for(int i=len_a-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
