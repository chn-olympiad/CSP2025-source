#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in""r",stdin);
    freopen("number.out""w",stdout);
    char str[10000000];
    cin>>str;
    int len=strlen(str);
    int arr[len+5]={0},m=0;
    char s[len+5];
    for(int i=0;i<len;i++){
        if(str[i]>='1'&&str[i]<='9'){
            s[i]=str[i];

            m++;
        }
    }
    for(int i=0;i<m;i++){
        arr[i]=s[i]-'0';
    }
    int z=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
          if(arr[j]<arr[j+1]){
                z=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=z;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<arr[i];
    }
    return 0;
}
