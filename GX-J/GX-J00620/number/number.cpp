#include<bits/stdc++.h>
using namespace std;
int a[1000000]={-1},b,c=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=sizeof(s);
	for(int i=0;i<b-1;i++){
        if(s[i]-'0'<10 && s[i]-'0'>=0){
                c++;
            a[i]=int(s[i]-'0');
            cout<<a[i]<<' '<<s[i]<<endl;}
	}
	sort(a,a+b);
	for(int i=b-1;i>b-c-1;i--){
        if(a[i]>=0)
            cout<<a[i];
	}
	return 0;
}
