#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string s;
long long a[N],vis[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("numder.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			while(a[i]){
			    cout<<i;
			    a[i]-=1;
			}
		}
	}
	return 0;
}
