#include<bits/stdc++.h>
using namespace std;
int s[1001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int cnt=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			cnt++;
			s[cnt]=a[i]-'0';
		}
	}
	sort(s+1,s+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
  return 0;
}
