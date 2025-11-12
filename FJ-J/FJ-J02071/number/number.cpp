#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+5;
string s;
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int q=s[i]-'0';
			a[++cnt]=q;
		}
	} 
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
