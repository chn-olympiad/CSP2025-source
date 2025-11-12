#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a=s.size(),arr[1000005],count=0;
    for(int i=0;i<a;i++){
        if(s[i]>='0'&&s[i]<='9'){
            
            arr[count]=s[i]-'0';
            count++;
        }
    }
    sort(arr,arr+count,cmp);
    if(arr[0]==0){
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=0;i<count;i++){
        cout<<arr[i];
    }    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
