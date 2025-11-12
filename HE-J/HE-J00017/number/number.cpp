#include<bits/stdc++.h>
using namespace std;
int a[9];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=s.size();
	for(int i=0;i<=b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(int)s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
		    cout<<i;
	    }
	}
	return 0;
}
