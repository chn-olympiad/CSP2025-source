#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define ll unsigned long long
string str;
int a[N];
ll ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    int len=0;
    int sz=str.size();
    for(int i=0;i<sz;i++){
	    if(str[i]-'0'>=0&&str[i]-'0'<=9){
		    a[++len]=str[i]-'0';
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=1;i--){
	    cout<<a[i];
	}
	cout<<"\n"; 
    return 0;
}
