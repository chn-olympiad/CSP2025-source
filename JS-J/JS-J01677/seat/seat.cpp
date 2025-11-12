#include<bits/stdc++.h>
using namespace std;

int l,h,ansl,ansh;
int num[100000],zhu;

int dao(int h,int ansh){
    int num[h+1][2];
    for(int f=1;f<=h;f++){
        num[f][0]=f;
        num[f][1]=h+1-f;
        if(f==ansh)return num[f][1];
        }
    return 0;
}

int pai(int a,int b){
    return a>b;
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>h>>l;

    cin>>num[0];
    zhu=num[0];


    for(int f=1;f<l*h;f++){
        cin>>num[f];
    }
    sort(num,num+l*h,pai);

    for(int f=0;f<l*h;f++){
        if(num[f]==zhu){
            zhu=f+1;
        }
    }

    //cout<<" zhu"<<zhu<<" h"<<h<<" l"<<l<<" ceil zhu/l"<<ceil(double(zhu)/l);
    ansl=ceil(double(zhu)/h);
    if(ansl%2==1){
        ansh=zhu;
        while(ansh>h){
            ansh-=h;
        }
    }

    else{
        ansh=zhu;
        //cout<<"!!!!!!"<<ansh<<endl;
        while(ansh>h){
            //cout<<"while**ansh"<<ansh<<" h "<<h<<endl;
            ansh-=h;
        }
        //cout<<"jieshu"<<ansh<<endl;
        ansh=dao(h,ansh);
    }
    cout<<ansl<<" "<<ansh;



    return 0;
}
