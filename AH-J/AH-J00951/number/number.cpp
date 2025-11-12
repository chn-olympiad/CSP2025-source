#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
long long n,ss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			ss++;
		}
	}
	for(int ir=9;ir>=0;ir--){
		if(a[ir]!=0){
			for(int j=1;j<=a[ir];j++){
				cout<<ir;
			}
		}
	}
	cout<<endl;
	return 0;
}

