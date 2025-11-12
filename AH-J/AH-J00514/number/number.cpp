#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int n[1000001];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l;
    for(unsigned int i=0,j=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			n[j]=s[i]-'0';
			j++;
			l++;
		}
	}
	sort(n+0,n+0+l);
	for(int i=l-1;i>=0;i--)
		cout<<n[i];
	return 0;
}
