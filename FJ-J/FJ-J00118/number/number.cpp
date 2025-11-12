#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],maxs,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		t=s[i]-'0';
		if(t>=0&&t<=9){
			a[t]++;
			if(t>maxs){
				maxs=t;
			}
		}
	}
	if(maxs==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
