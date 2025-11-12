#include<bits/stdc++.h>
using namespace std;
string s;
int a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int x;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			x=s[i]-48;
			a[x]++;
		}
	}

	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			cout<<i;
			a[i]--;
			if(a[i]!=0){
				i++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
