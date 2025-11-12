#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long i;
	long long sum=0;
	long long l=s.size();
	for(i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(i=sum;i>=1;i--){
		printf("%d",a[i]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
