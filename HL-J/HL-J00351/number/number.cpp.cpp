
#include <bits/stdc++.h>
using namespace std;
freopen("number.in","r",stdin)
freopen("number.out","w",stdout)
	string s;
	char a[1000100];
	int i,n;
int main(){
	cin>>s;
	for(int i=0;i<=s.size;++i){
		if(0<=s[i]&&s[i]<=9){
			n++;
		a[n]=s[i];	
		}
	}
	for(i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
