#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sum=0;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='2'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='3'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='4'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='5'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='6'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='7'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='8'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='9'){
			a[i]=s[i]-'0';
			ans++;
		}
		if(s[i]=='0'){
			sum++;
		}
	}
	for(int j=0;j<ans;j++){
	    for(int i=0;i<s.size();i++){
	    	int m=a[i],n=a[i+1];
			if(a[i]<a[i+1]&&a[i]!=0&&a[i+1]!=0){
				a[i]=n;
				a[i+1]=m;
			}
       } 
    }
	for(int i=0;i<s.size();i++){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	if(sum!=0){
	    for(int i=0;i<sum;i++){
		    cout<<0;
	    }
    }
	return 0;
}
