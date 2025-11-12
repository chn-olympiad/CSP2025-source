# include<bits/stdc++.h>
 using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","r",stdout);
char s[1000005];
char a[1000005];
int j=1;

for(int i=1;;i++){
       cin>>s[i];
        if(s[i]==','){
break;}

if(s[i]>='0'&&s[i]<='9'){
        a[j]=s[i];
        j++;
}
}
sort(a+1,a+j+1);
for(int i=j;i>=1;i--){
    cout<<a[i];
}
return 0;
}
