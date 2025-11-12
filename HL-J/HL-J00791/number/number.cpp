#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),cnt=0;
	int a[l-1];	
	int t=0;
	for(int i=0;i<l;i++){	
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[t]=s[i]-'0';
			t++;
		}
		else{
			cnt++;
		}
	}
	if(cnt>=1){
		l-=cnt;
	}
	sort(a+0,a+l,cmp);
	for(int i=0;i<l;i++){
		cout<<a[i];
	}	
	

	
	return 0;
}
