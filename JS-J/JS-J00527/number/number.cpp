#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='z'&&s[i]>='a'){
			continue;
		}
		else{
			a[i]=s[i];
			sum++;
		}
	}
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
