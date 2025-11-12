#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	int k=1;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	for(int i=1;i<k;i++){
		b[a[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=b[i];j++){
			cout<<i;
		}
	}
return 0;	
}
