#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(auto i:s){
		if('0'<=i&&i<'9'){
			v.push_back(int(i-'0'));
		}
	}
	sort(v.begin(),v.end());
	int n=v.size();
	bool zflag=0;
	if(n==0){
		cout<<0<<endl;
		return 0;
	}else{
		n--;
		zflag=(v[n]>0);
	}
	if(zflag){
		while(n>=0){
			cout<<v[n];
			n--;
		}
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
}
