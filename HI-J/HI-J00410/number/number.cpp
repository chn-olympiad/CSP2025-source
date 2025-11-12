#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000050];
int c=1;
bool f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[c]=s[i]-48;
			if(a[c]!=0){
				f=1;
			}
    		c++;
    		
		}
	}
	sort(a+1,a+c);
	if(f!=0){
		for(int i=c-1;i>=1;i--){
			cout<<a[i];
	    }	
	    return 0;
	}
	else{
		cout<<"0";
	}
	return 0;
}
