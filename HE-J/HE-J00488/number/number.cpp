#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>s;
	for(int i=0;i<s.size();i++){
		
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}
		else a[i]=-1;
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--){
		if(a[i]==-1){
		}
		else cout<<a[i];
	}
	return 0;	
}
