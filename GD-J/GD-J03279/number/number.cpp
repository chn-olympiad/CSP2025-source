#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int A[N],tot;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
		if(isdigit(s[i]))
			A[++tot]=int(s[i]-'0');
	sort(A+1,A+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		cout<<A[i];
	return 0;
} 
