#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int a[N];
long long q=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
		cin>>s;
	
	if(s.size()==1){
		for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cout<<s;
			return 0;
	}
		}
	}
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
			a[i]+=s[i]-'0';
			q++;	
			}
		}
		
		sort(a,a+s.size());
		
		for(int i=s.size()-1;i>=s.size()-q;i--){
			
			if(i>=0)
		cout<<a[i];
		else
		break;
		
		}
	return 0;
} 

