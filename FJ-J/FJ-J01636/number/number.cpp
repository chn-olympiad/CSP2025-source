#include<bits/stdc++.h>
using namespace std;
int d[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);//让优化保佑我AC2题 
    cin.tie(0),cout.tie(0);
	cin>>s;
	int si=s.size()-1;
	for(int i=0;i<=si;i++){
		if(s[i]>='0' && s[i]<='9'){
			int n=s[i]-'0';
			d[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(d[i]>0){
			for(int j=1;j<=d[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
