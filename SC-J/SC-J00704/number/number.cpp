#include<bits/stdc++.h>
using namespace std;
char a[1100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=s.size();
    int j=1;
	for(int i=0;i<b;i++){
		if(s[i]>=48&&s[i]<=57){
			a[j]=s[i];
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}