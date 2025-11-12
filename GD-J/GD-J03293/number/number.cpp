#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 1000005
string s;
vector<int> a;
int p[Max];
ll m;
char op;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]<='9'&&s[i]>='0'){
    		a.push_back(s[i]-48);
		}
	}
	m=a.size();
	for(int i=0;i<a.size();i++){
		p[i]=a[i];
	}
	sort(p,p+m);
	for(int i=m-1;i>=0;i--){
		cout<<p[i];
	}
// 0->48


	return 0;
} 
