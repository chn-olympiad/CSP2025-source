#include<bits/stdc++.h>
#include<string>
using namespace std;
int a[11];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++) if('0'<=s[i]&&s[i]<='9') a[int(s[i])-48]++;
	
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
