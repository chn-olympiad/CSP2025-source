#include<bits/stdc++.h>
using namespace std;
string s,k;
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	for(int i=0;i<k.size();i++){
		if(k[i]>='0'&&k[i]<='9')s+=k[i];
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
