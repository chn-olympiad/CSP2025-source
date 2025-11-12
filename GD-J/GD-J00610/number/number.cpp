#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
char c;
char v;
long long b[999999]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		c=s[i];
		if(c>='0'&&c<='9'){
			b[sum]=(c-'0');
			sum++;
		}
	}
	sort(b,b+sum);
	for(int i=sum-1;i>=0;i--){
		cout<<b[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
