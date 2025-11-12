#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(int x,int y){
	return x>y;
}
int a[10000006],sum;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}