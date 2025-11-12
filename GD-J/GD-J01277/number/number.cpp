#include<bits/stdc++.h>
using namespace std;
string s;
long long l,a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
