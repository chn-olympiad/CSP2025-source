#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	bool flag=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]!='0')flag=1;
			a[n++]=s[i]-'0';
		}
	}
	sort(a,a+n,cmp);
	if(flag==0){
		cout<<0;
	}else{
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
	}
	return 0;
} 
