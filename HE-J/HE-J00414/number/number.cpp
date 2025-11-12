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
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+0,a+k,cmp);
	bool x=0;
	for(int i=0;i<k;i++){
		if(a[i]!=0)
		x=1;
	} 
	if(x==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	if(k==0)cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
