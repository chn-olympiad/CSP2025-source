#include<bits/stdc++.h>
using namespace std;
string a;
vector<string> s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' || a[i]=='0'){
			for(int j=1;j<=len;j++){
				s[j]=a[i];
			}
		}
		else{
			continue;
		}
	}
	sort(s.end(),s.begin());
	int siz=s.size();
	for(int i=1;i<=siz;i++){
		cout<<s[i];
	}
	return 0;
}