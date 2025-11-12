#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char str[1000005];
int arr[1000005];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",str);
    int len=strlen(str);
    int idx=0;
    for(int i=0;i<len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            arr[idx]=str[i]-'0';
            idx++;
        }
    }
    sort(arr,arr+idx,cmp);
    for(int i=0;i<idx;i++){
        printf("%d",arr[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
