#include<bits/stdc++.h> 
using namespace std;
int n,a[1000005],b[20],cnt;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int si=s.size();
	for(int i=1;i<=si;i++) {
		if(s[i-1]<='9'&&s[i-1]>='0') {
			a[s[i-1]-'0']++;
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=9;j>=0;j--){
			if(a[j]>0){
				cout<<j;
				a[j]--;
				j++;
			}
		}
	}
	return 0;
} 



