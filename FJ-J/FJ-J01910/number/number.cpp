#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],ap[100005],cnt;
int main(){
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>s;
	int le=s.size();
	for(int i=0;i<le;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[i]=s[i]-'0';
			cnt++;

		}
		
	}
	sort(a,a+le);
	for(int i=le-1;i>=le-cnt;i--){
		cout<<a[i];

	}
	return 0;
} 



