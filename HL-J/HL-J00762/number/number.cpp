#include<bits/stdc++.h>
using namespace std;
string s;
int j,a[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			//cout<<s[i];
			a[j]=s[i]-'0';
			//cout<<" "<<a[j];
			j++;
		}
	}sort(a,a+j,cmp);
	//cout<<a[0];
	for(int i=0;i<j;i++){
		cout<<a[i];
	}
	return 0;
}
