#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a[1145145];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int n=1;
	for(int i=0;i<s1.size();i++){
		if('0'<=s1[i]&&s1[i]<='9'){
			a[n]=s1[i]-'0';
			n++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
