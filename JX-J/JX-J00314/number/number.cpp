#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int A[N],tot=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9') A[++tot]=s[i]-'0';
	}
	sort(A+1,A+tot+1);
	for(int i=tot;i>=1;i--){
		printf("%d",A[i]);
	}		
	return 0;
}
