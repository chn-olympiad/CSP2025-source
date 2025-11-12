#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=1;
	int len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a+1,a+sum);
	if(a[sum-1]==0){
		printf("0");
		return 0;
	}
	for(int i=sum-1;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
} 
