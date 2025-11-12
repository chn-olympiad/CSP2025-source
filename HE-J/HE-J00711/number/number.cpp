#include<bits/stdc++.h>
using namespace std;

string s;
long long a[1000086]={0};

bool cmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int i,j=0;
	for(i=0;i<s.length();i++){
		if(s[i]>=48 and s[i]<=57){
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a,a+s.length(),cmp);
	for(i=0;i<j;i++){
			cout<<a[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
