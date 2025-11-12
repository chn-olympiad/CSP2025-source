#include <bits/stdc++.h>
using namespace std;
string a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long flag=1;
	string s;
	cin>>s;
	for(long long i=1;i<=s.size();i++){
		a[i]=s[i-1];
	}
	
	sort(a+1,a+s.length()+1);
	
	
	
	for(long long i=1;i<=s.size();i++){
		if(a[i]!="1" &&a[i]!="2" &&a[i]!="3" &&a[i]!="4" &&a[i]!="5" &&a[i]!="6" &&a[i]!="7" &&a[i]!="8" &&a[i]!="9" &&a[i]!="0"){
			flag=i-1;
			break;
		}else{
			flag=s.size();
		}
	}
	for(long long i=flag;i>=0;i--){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
