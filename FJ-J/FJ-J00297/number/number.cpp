#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='0'){
				a[k]=0;
			}else if(s[i]=='1'){
				a[k]=1;
			}else{
				a[k]=s[i]-'0';
			}
		    k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=1;i--){
		cout<<a[i];
	}
	cout<<c;
	return 0;
}
