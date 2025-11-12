#include<bits/stdc++.h>
using namespace std;
char c;
long long a[10],len;
string s,l;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>l;
	len=l.size();
	for(int i=0;i<=len;i++){
		c=l[i];
		if(c>='0'&&c<='9'){
			a[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			a[i]--;
			c=i+'0';
			s=s+c;
		}
	}
	cout<<s<<endl;

	return 0;
}
