#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    int s[100005]={},i=0;
    while(cin>>a){
            i++;
        if(a >= '0' and a <= '9'){
            s[i]=a-'0';
        }
        if(a == '/n'){
            break;
        }
    }
    sort(s+1,s+1+1,cmp);
    int j=1;
    while(s[j]!=0){
        cout<<s[j];
        j++;
    }
    return 0;
}
/*



                     _______                        _   _   _
        ___         | ______|      _______         | |_| |_| |      __
       /  /         | ______|     |___  __|        |____  ___|     |  |
      /   \         | |_\ \_         / /__             / /_        |  |
     /  /\ \        | ____  |       / __  \           / __ \       |  |
    /  /  \ \       | |_  \ \_     / / _/ /          / / / /       |  |
   /__/    \_\      |__/   \_/    /_/  \_/          /  \/ /        |  |
                                                   /_/\  /         |__|
                                                      / /           __
                                                     / /           |  |
                                                    / /            |__|
                                                   /_/


*/
