#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=0; 
	int f=0;
	int c=s.size();
	for(int i=0;i<c;i++){
		if(s[i]=='0'|| s[i]=='1'|| s[i]=='2'|| s[i]=='3'|| s[i]=='4'||s[i]=='5'|| s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
    
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	
	return 0;
}