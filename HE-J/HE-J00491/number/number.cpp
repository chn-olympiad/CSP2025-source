#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int n,p;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%s",s+1);
	//cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;++i){
        if(s[i]>='0'&&s[i]<='9'){
        	++p;
            a[p]=s[i]-'0';
        }
    }
    sort(a+1,a+p+1);
    for(int i=p;i>=1;--i){
        printf("%d",a[i]);
    }
    return 0;
}
