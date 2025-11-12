#include<bits/stdc++.h>
using namespace std;
bool cmp(const char &x,const char &y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s,x;
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		if(isdigit(s[i])){
			x+=s[i];
		}
	}
	sort(x.begin(),x.end(),cmp);
	cout<<x;
	return 0;
}
