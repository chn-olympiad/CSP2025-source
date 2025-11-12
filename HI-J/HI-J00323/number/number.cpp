#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],k=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
