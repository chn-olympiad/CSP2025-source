#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int n=s.length();
    int t=0;
    for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[t++]=int(s[i])-48;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		cout<<a[i];
	} 
    return 0;
}

