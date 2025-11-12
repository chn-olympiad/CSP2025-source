#include<bits/stdc++.h>
using namespace std;
string s;
long long len=0,num=0,a[100010];
bool ent(int x,int y){
    return x<y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len = s.size();
    for(int j=0;j<len;j++){
        if(s[j]==0){
            a[num] = s[j];
        }else if(s[j]==1){
            a[num] = s[j];
        }else if(s[j]==2){
            a[num] = s[j];
        }else if(s[j]==3){
            a[num] = s[j];
        }else if(s[j]==4){
            a[num] = s[j];
        }else if(s[j]==5){
            a[num] = s[j];
        }else if(s[j]==6){
            a[num] = s[j];
        }else if(s[j]==7){
            a[num] = s[j];
        }else if(s[j]==8){
            a[num] = s[j];
        }else if(s[j]==9){
            a[num] = s[j];
        }
        num++;
    }
    sort(a,a+1,ent);
    for(int j=0;j<num;j++){
        cout<<a[j];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
