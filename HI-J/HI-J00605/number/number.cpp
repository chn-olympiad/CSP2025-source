#include<bits/stdc++.h>
using namespace std;
string s;
int c[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l=0;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]=='0'){
			l++;
			c[l]=s[i]-'0';
		}
		else if(s[i]=='1'){
			l++;
			c[l]=s[i]-'0';	
		}
		else if(s[i]=='2'){
			l++;
			c[l]=s[i]-'0';	
		}
		else if(s[i]=='3'){
			l++;
			c[l]=s[i]-'0';	
		}
		else if(s[i]=='4'){
			l++;
			c[l]=s[i]-'0';			
		}
		else if(s[i]=='5'){
			l++;
			c[l]=s[i]-'0';
			
		}
		else if(s[i]=='6'){
			l++;
			c[l]=s[i]-'0';
			
		}
		else if(s[i]=='7'){
			l++;
			c[l]=s[i]-'0';
			
		}
		else if(s[i]=='8'){
			l++;
			c[l]=s[i]-'0';
		}
		else if(s[i]=='9'){
			l++;
			c[l]=s[i]-'0';
		}
	}
	sort(c+1,c+1+l);
	for(int i=l;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
