#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int step=0;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[step]=s[i]-'0';
			step++;
		}
	}
	sort(a,a+step);
	for(int i=step-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
