#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.in","w",stdin);
    char a;
    int ans[10]={0,0,0,0,0,0,0,0,0,0};
    int s=0,x=0;
    for (int i=0;i<1e6+5;i++){
        scanf("%c",&a);
        x="a"-a;
        if (x>0){
            if (a=="0"){
                ans[0]++;
            }else if (a=="1"){
                ans[1]++;
            }else if (a=="2"){
                ans[2]++;
            }else if (a=="3"){
                ans[3]++;
            }else if (a=="4"){
                ans[4]++;
            }else if (a=="5"){
                ans[5]++;
            }else if (a=="6"){
                ans[6]++;
            }else if (a=="7"){
                ans[7]++;
            }else if (a=="8"){
                ans[8]++;
            }else{
                ans[9]++;
            }
    }
    for (int j=9;j>=0;j--){
        for (int k=ans[j];k>0;k--){
            printf("%d",j);
        }
    }
    return 0;
}
