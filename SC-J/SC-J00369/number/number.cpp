#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000002]={},k=0;
bool cmp(int a,int b){
	return a>b;
}
string str;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if('0'<=str[i]&&str[i]<='9'){
			a[k]=str[i]-'0'; 
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++)cout<<a[i];
	cout<<"\n" ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
