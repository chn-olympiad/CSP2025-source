#include<bits/stdc++.h>
using namespace std;
int aa=0,bb=0,cc=0;
struct Node{
    int a,b,c,cho;
    int deab,deac,debc;
    bool ab,ac,bc;
};
Node arr[100010];
int n;
int top=0,top1=0,top2=0;
int ans;
Node arr1[100010],arr2[100010];
bool cmpab(Node a11,Node b11){
    return a11.deab<b11.deab;
}
bool cmpac(Node a11,Node b11){
    return a11.deac<b11.deac;
}
bool cmpbc(Node a11,Node b11){
    return a11.debc<b11.debc;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdour);
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        cin>>n;
        aa=0,bb=0,cc=0,top=0,top1=0,top2=0;
        for(int i=0;i<n;i++){
            cin>>arr[i].a;
            cin>>arr[i].b;
            cin>>arr[i].c;
            arr[i].deab=abs(arr[i].a-arr[i].b);
            arr[i].deac=abs(arr[i].a-arr[i].c);
            arr[i].debc=abs(arr[i].b-arr[i].b);
            arr[i].ab=0;
            arr[i].ac=0;
            arr[i].bc=0;
            if((arr[i].a-arr[i].b)>=0) arr[i].ab=1;
            if((arr[i].a-arr[i].c)>=0) arr[i].ac=1;
            if((arr[i].b-arr[i].c)>=0) arr[i].bc=1;
            if(arr[i].a>arr[i].b && arr[i].a>arr[i].c){
                arr[i].cho=1;
                aa++;
                ans+=arr[i].a;

            } else if(arr[i].b>arr[i].a && arr[i].b>arr[i].c) {
                arr[i].cho=2;
                bb++;
                ans+=arr[i].b;

            }else{
                arr[i].cho=3;
                cc++;
                ans+=arr[i].c;

            }
        }
        for(int i=0;i<n;i++){
            arr1[i].a=arr[i].a;
            arr1[i].a=arr[i].b;
            arr1[i].a=arr[i].c;
            arr2[i].a=arr[i].a;
            arr2[i].a=arr[i].b;
            arr2[i].a=arr[i].c;
            arr1[i].deab=abs(arr[i].a-arr[i].b);
            arr1[i].deac=abs(arr[i].a-arr[i].c);
            arr1[i].debc=abs(arr[i].c-arr[i].b);
            arr2[i].deab=abs(arr[i].a-arr[i].b);
            arr2[i].deac=abs(arr[i].a-arr[i].c);
            arr2[i].debc=abs(arr[i].c-arr[i].b);
        }

        sort(arr,arr+n,cmpab);
        sort(arr1,arr1+n,cmpac);
        sort(arr2,arr2+n,cmpbc);
        if(aa>(n/2)){

            for(int i=0;i<(aa-(n/2));i++){
//                cout<<
                if((bb+1)<=(n/2)&&arr[i].ab==1&&(cc+1)<=(n/2)&&arr[i].ac==1){

                    if(arr[top].deab<arr1[top1].deac ){
                        ans-=arr[top].deab;
                        bb++;
                        top++;
//                        cout<<"ans1"<<ans<<endl;
                    }else {
                        ans-=arr2[top2].deac;
                        cc++;
                        top2++;
 //                       cout<<"ans2"<<ans<<endl;
                    }
                }else if((bb+1)<=(n/2)&& arr[top].ab==1){
                        ans-=arr[top].deab;
                        bb++;
                        top++;
                }else if((cc+1)<=(n/2)&&arr1[top1].ac==1){
                        ans-=arr1[top1].deac;
                        cc++;
                        top1++;
                }
            }
            aa=(n/2);
        }
        top=0,top1=0,top2=0;

        if(bb>(n/2)){
            for(int i=0;i<(bb-(n/2));i++){
                if((aa+1)<=(n/2)&&arr[i].ab==0&&(cc+1)<=(n/2)&&arr[i].bc==1){
                    if(arr[top].deab<arr2[top2].debc ){
                        ans-=arr[top].deab;
                        aa++;
                        top++;
                    }else {
                        ans-=arr2[top2].debc;
                        cc++;
                        top2++;
                    }
                }else if((aa+1)<=(n/2)&& arr[top].ab==0){
                        ans-=arr[top].deab;
                        aa++;
                        top++;
                }else if((cc+1)<=(n/2)&&arr1[top1].ac==1){

                    ans-=arr2[top2].debc;
                    cc++;
                    top2++;
                }
            }
            bb=(n/2);
        }
        top=0,top1=0,top2=0;

        if(cc>(n/2)){
            for(int i=0;i<(cc-(n/2));i++){
                if((aa+1)<=(n/2)&&arr[i].ac==0&&(bb+1)<=(n/2)&&arr[i].bc==0){
                    if(arr1[top1].deac<arr1[top2].debc ){
                        ans-=arr1[top1].deac;
                        aa++;
                        top1++;
                    }else {
                        ans-=arr2[top2].debc;
                        bb++;
                        top2++;
                    }
                }else if((aa+1)<=(n/2)&&arr1[top1].ac==0){
                        ans-=arr1[top1].deac;
                        aa++;
                        top1++;
                }else if((bb+1)<=(n/2)&&arr2[top2].bc==0){
                        ans-=arr2[top2].debc;
                        bb++;
                        top2++;
                }
            }
            aa=(n/2);
        }
        cout<<ans<<endl;
    }

}
