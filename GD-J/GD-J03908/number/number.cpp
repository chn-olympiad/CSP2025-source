#include <bits/stdc++.h>
using namespace std;
long long n,m,nm,op,sum,sum1,i,j,k,a[1000005],b[1000005],mid,ans,max1=114514114514114514,min1=-114514114514114514;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(long long)(s[i]-'0')]++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=a[i];j++)printf("%lld",i);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
