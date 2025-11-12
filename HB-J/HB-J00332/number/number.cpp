#include<bits/stdc++.h>
using namespace std;
string s;
int ls;
long long asw;
vector<int>a;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
           ls=s[i]-'0';
           a.push_back(ls);
    	}
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=a.size()-1;i>=0;i--){
        asw=asw*10+a[i];
    }
    cout<<asw;
	return 0;
}
