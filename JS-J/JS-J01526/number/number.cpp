#include<bits/stdc++.h>
using namespace std;
long long a[100001],i;
int main(){
    char c;
    while((c=getchar())!='\n'){
        if(c>='0'&&c<='9'){
            a[i]=c-'0';
            i++;
        }
    }
    sort(a,a+i);
    for(int j=i-1;j>=0;j--)cout<<a[j];
    return 0;
}
