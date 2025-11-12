#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000010]={-1};
	string s;
	cin>>s;
	int ind=0;
	for (int i=0;i<s.size();i++){
		if ('0'<=s[i]&&s[i]<='9'){
			a[ind]=s[i]-'0';
			ind++;
		}
	}
	int t=0;
	for (int i=0;i<ind;i++){
		for (int j=1;j<ind;j++){
			if (a[j-1]<a[j]){
				t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
			}
		}
	}
	for (int i=0;i<ind;i++){
		cout<<a[i];
	}
	return 0;
}
