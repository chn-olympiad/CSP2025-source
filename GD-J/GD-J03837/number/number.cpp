#include<bits/stdc++.h>
using namespace std;
char a[100000000010]={};
long long k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<=s.length()-1;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[k]=s[i];
			k++;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

