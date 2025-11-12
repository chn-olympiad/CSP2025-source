#include <bits/stdc++.h>
using namespace std;
//finished for GX-J01153
bool sortrule(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int lis[10024]={-1};
    string in;
    cin>>in;
    in += '!';
    int ljq=-1, ling=0;
    for(int i=0;in[i]!='!';i++){
        if(in[i]>='0'&&in[i]<='9'){
            ljq++;
            lis[ljq] = in[i]-48;
            cout<<ljq<<" ";
        }
    }//ShenMeJiBaTiMu QAQ(Get Number)
    sort(lis+0,lis+ljq+1,sortrule);

    for(int i=0;i<ljq+1;i++){
        if(lis[i]==-1)continue;
        cout<<lis[i];
    }//KaiXinPianFen(bushi


    return 0;
}
