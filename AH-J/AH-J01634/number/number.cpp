#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(const char&x,const char& y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,s;
	cin>>a;
	ll al=a.size();
	for(ll i=0;i<al;i++){
		if(isdigit(a[i])){
			s+=a[i];
		}
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
