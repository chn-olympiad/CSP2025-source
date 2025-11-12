#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len1=s.size(),j=0;
	if(len1==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<len1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=int(s[i]-48);
			j++;
		}
	}
	sort(a,a+j,cmp);
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

