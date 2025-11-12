#include<bits/stdc++.h>
using namespace std;
int n[114514],i,s,numb=0,an[114514];
string x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>x;
    for(i=0;i<=x.size()-1;i++){
        if(x[i]>='0'&&x[i]<='9'){
            numb++;
            an[numb]=x[i]-'0';
        }
    }
    sort(an+1,an+numb+1);
    s=numb;
    if(numb%2!=0&&numb>3){
        for(i=1;i<=numb;i++){
            if(s==(numb/2+1)){
                break;
            }
            swap(an[i],an[s]);
            s--;

        }
    }
    else if(numb==1){
        cout<<an[1];
        return 0;
    }
    else if(numb==3){
        swap(an[1],an[3]);
    }
    else if(numb%2==0){
        for(i=1;i<=numb;i++){
            if(s==numb/2){
                break;
            }
            swap(an[i],an[s]);
            s--;
        }
    }
    for(i=1;i<=numb;i++){
        cout<<an[i];
    }
    return 0;
}
