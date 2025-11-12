#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100],cnt;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[(s[i]-'0')]++;		
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	
	return 0;
}
