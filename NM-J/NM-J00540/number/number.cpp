#include<bits/stdc++.h>
using namespace std;

int a[100000000];
char s[100000000];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int sum=0;
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            a[i]=0;
            sum++;
        }else if(s[i]=='1'){
            a[i]=1;
            sum++;
        }else if(s[i]=='2'){
            a[i]=2;
            sum++;
        }else if(s[i]=='3'){
            a[i]=3;
            sum++;
        }else if(s[i]=='4'){
            a[i]=4;
            sum++;
        }else if(s[i]=='5'){
            a[i]=5;
            sum++;
        }else if(s[i]=='6'){
            a[i]=6;
            sum++;
        }else if(s[i]=='7'){
            a[i]=7;
            sum++;
        }else if(s[i]=='8'){
            a[i]=8;
            sum++;
        }else if(s[i]=='9'){
            a[i]=9;
            sum++;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=2;j<=n-i;j++){
            if(a[j]>a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
    for(int i=1;i<=sum;i++){
        printf("%d",a[i]);
    }
    return 0;
}
