#include<bits/stdc++.h>
using namespace std;

long long a[100];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[s[i]-'0']+=1;		
		}
	}
	for(int i=9;i>=0;i--) {
		if(a[i]>=1) {
			for(int j=1;j<=a[i];j++) {
				printf("%d",i);
			}
		}
	}
//#Shang4Shan3Ruo6Shui4
	return 0;
}
