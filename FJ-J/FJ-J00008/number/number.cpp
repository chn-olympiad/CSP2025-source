#include<bits/stdc++.h>
using namespace std;
string s;
long long ma=0,a[1000005]={},j=1,number=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size();
	if(len==1){
		cout<<s;
		return 0;
	} 
	for(int i=0;i<len;i++){
		if(s[i]=='9'){
			a[j]=9;
			j++;
		}else if(s[i]=='8'){
			a[j]=8;
			j++;
		}else if(s[i]=='7'){
			a[j]=7;
			j++;
		}else if(s[i]=='6'){
			a[j]=6;
			j++;
		}else if(s[i]=='5'){
			a[j]=5;
			j++;
		}else if(s[i]=='4'){
			a[j]=4;
			j++;
		}else if(s[i]=='3'){
			a[j]=3;
			j++;
		}else if(s[i]=='2'){
			a[j]=2;
			j++;
		}else if(s[i]=='1'){
			a[j]=1;
			j++;
		}else if(s[i]=='0'){
			a[j]=0;
			j++;
		}
	}
	j=j-1;
	sort(a+1,a+j+1);
	for(int i=j;i>=1;i--){
		number=number*10+a[i];
	}
	cout<<number;
	return 0;
} 
