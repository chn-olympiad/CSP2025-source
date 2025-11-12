#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (isdigit(s[i])){
			ans++;
			if (s[i]=='0'){
				a[ans]=0;
			}else if (s[i]=='1'){
				a[ans]=1;
			}else if (s[i]=='2'){
				a[ans]=2;
			}else if (s[i]=='3'){
				a[ans]=3;
			}else if (s[i]=='4'){
				a[ans]=4;
			}else if (s[i]=='5'){
				a[ans]=5;
			}else if (s[i]=='6'){
				a[ans]=6;
			}else if (s[i]=='7'){
				a[ans]=7;
			}else if (s[i]=='8'){
				a[ans]=8;
			}else if (s[i]=='9'){
				a[ans]=9;
			}
			
		}
	}

	sort (a+1,a+1+ans);
	for (int i=ans;i>=1;i--){
		
		cout<<a[i];
	}
	return 0;
}

