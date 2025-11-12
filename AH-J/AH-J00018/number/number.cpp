#include<bits/stdc++.h>
using namespace std;
int n,m,ans,sum,t,a[20];
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>s){
	    if('0'<=s&&s<='9'){
			a[s-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
	    while(a[i]){
		    cout<<i;
		    a[i]--;
		}
	}
	cout<<endl;
	return 0;
}
