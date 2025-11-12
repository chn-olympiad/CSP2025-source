#include<bits/stdc++.h>
using namespace std;

int a[1000010];
long long a_size=0;


int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int i;
	cin>>s;
	long long n=s.size();
	for(i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++a_size]=s[i]-'0';
		}
	}
	sort(a+1,a+a_size+1);
	for(i=a_size;i>=1;i--){
		printf("%d",a[i]);
	}
	printf("\n");
	
	return 0;
}
