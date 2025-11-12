#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt,len;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=(s[i]-48);
		}
	}
	sort(a+1,a+cnt+1,cmp);
	bool is_zero=true;
	for(int i=1;i<=cnt;i++){
		if(i==1&&a[i]==0){
			is_zero=false;
			break;
		}
	}
	if(is_zero){
		for(int i=1;i<=cnt;i++){
			cout<<a[i];
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
