#include<bits/stdc++.h>
using namespace std;
char s[10005];
char a[10005],k=0;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
fgets(s,10005,stdin);
for(int i=0;i<=10005;i++){
    if('0'<=char(s[i])&&char(s[i])<='9'){
        a[k]=s[i];
        k++;
    }
}
sort(a,a+k+1);
for(int i=k;i>=0;i--){
    cout<<a[i];
}
fclose(stdin);
fclose(stdout);
return 0;
}
