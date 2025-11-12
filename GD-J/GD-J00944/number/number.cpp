#include<bits/stdc++.h>
using namespace std;
char s[100010],a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long j=0;
	for(long long i=0;i<sizeof(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i];
			j++;
		}
	}
	for(long long i=0;i<j;i++){
		for(long long k=0;k<j;k++){
			if(a[i]>a[k]) swap(a[i],a[k]);
		}
	}
	for(long long i=0;i<j;i++) cout<<a[i];
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
