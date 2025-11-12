#include<bits/stdc++.h>
using namespace std;
char s[10001000];
int a[10001000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int len=strlen(s);
    int name=0;
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0'){
        	a[name]=s[i]-'0';
        	name++;
        }else {
	        continue;
        }
    }
    sort(a,a+name);
    for(int i=name-1;i>=0;i--){
    	printf("%d",a[i]);
    }
    return 0;
}
