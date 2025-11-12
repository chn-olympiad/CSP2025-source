#include<bits/stdc++.h>
using namespace std;

bool com(int a,int b){
    return a<b;
}

int doit(int n){
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i];
    int a1=0,b1=0,c1=0;
    int answer=0;
    int axcost[n],bxcost[n],cxcost[n];
    for(int i=0;i<n;i++){
        if(a[i]==max(a[i],b[i],c[i])){
            axcost[a1]=a[i]-max(b[i],c[i]);
            a1++;
        }
        else if(b[i]==max(a[i],b[i],c[i])){
             bxcost[b1]=b[i]-max(a[i],c[i]);
             b1++;
        }
        else{
            cxcost[c1]=c[i]-max(a[i],b[i]);
            c1++;
        }
        answer+=max(a[i],b[i],c[i]);
    }
    int k=n/2;
    if(a1>k||b1>k||c1>k){
        sort(axcost,axcost+a1,com);
        sort(bxcost,bxcost+b1,com);
        sort(cxcost,cxcost+c1,com);
        if(a1>k)
            for(int i=0;i<a1-k;i++)
                answer-=axcost[i];
        else if(b1>k)
            for(int i=0;i<b1-k;i++)
                answer-=bxcost[i];
        else
            for(int i=0;i<c1-k;i++)
                answer-=cxcost[i];
    }
    return answer;
}
int main(){
    int t;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++){
        cin>>a[i];
        cout<<doit(a[i])<<endl;
    }
    return 0;
}
