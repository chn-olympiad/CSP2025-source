#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int m=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<int (sizeof(s));i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=s[i];
			m++;
		}
	}sort(a+1,a+m+1);
	for(long long i=m;i>=1;i--){
		cout<<a[i];
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
