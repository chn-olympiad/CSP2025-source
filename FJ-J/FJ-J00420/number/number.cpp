#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
long long int result[N],use;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			use=s[i]-'0';
			cnt+=1;
			result[cnt]=use;
		}
	}
	sort(result+1,result+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<result[i];
	}
	return 0;
}
