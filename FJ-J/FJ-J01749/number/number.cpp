#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int j=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>=48 && s[i]<=57){
			a[j] = int(s[i])-48;
			j++;
		}
	}
	sort(a,a+j);
	if(a[j-1]==0){
		cout<<0;
	}
	else{
		for(int i=j-1;i>=0;i--){
			cout<<a[i];
		}
	} 
	return 0;
}
