#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len =s.size();
    int m=0;
    for(int i=0;i<=len-1;i++){
    	if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'|s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
    		a[i]=s[i]-'0';
		}
    	if(s[i]=='0'){
    		m++;
		}
	}
	int n=0;
	for(int i=0;i<=len-1;i++){
		if(a[i]==0){
			n++;
		}
	}
	int b=n-m;
	int c=len-b-1;
    for(int i=0;i<=len-1;i++){
    	for(int j=0;j<=len-1;j++){
    		if(a[i]>a[j]){
    			swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<=c;i++){
		cout<<a[i];
	}
    return 0;
}