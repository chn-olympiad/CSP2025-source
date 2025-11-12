#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=0;
	int a[100005]={};
	int cnt=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	} 
	sort(a,a+cnt);
	for(int i=cnt;i>=0;i--){
		sum=sum*10+a[i];
	}
	cout<<sum;
	return 0;
} 
