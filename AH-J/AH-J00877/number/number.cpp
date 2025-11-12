#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1100000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long n=0;
    long long len=s.size();
    long long j=0;
    for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=int(s[i]-'0');
			j++;
			n++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
    return 0;
}
//#Shang4Shan3Ruo6Shui4
