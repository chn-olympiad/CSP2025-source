#include<bits/stdc++.h>
using namespace std;
long long a1[100010],a2[100010],a3[100010];
int b1[100010],b2[100010],b3[100010];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
long long n,m,i,j,k,t,x1=1,x2=1,x3=1,s,ans=0,l,q,q1,Q,Q1,s1;
cin>>t;
for(j=1;j<=t;j++){
        cin>>n;
        ans=0;
        x1=1;
        x2=1;
        x3=1;
for(i=1;i<=n;i++){
    cin>>a1[i]>>a2[i]>>a3[i];
    k=n/2;
    if(a1[i]==max(a1[i],max(a2[i],a3[i]))){
        if(x1-1<k) {
                ans=ans+a1[i];
                b1[x1]=i;
               x1++;
        }
        else {
            //    cout<<"1"<<" ";
            if(a1[i]-a2[i]>a1[i]-a3[i]) {
                q=a1[i]-a3[i]; q1=3;
            }
            else {
                q=a1[i]-a2[i]; q1=2;
            }
            s=i;
            for(l=1;l<x1;l++){

                if(a1[b1[l]]-a2[b1[l]]>a1[b1[l]]-a3[b1[l]]) {
                Q=a1[b1[l]]-a3[b1[l]]; Q1=3;
            }
            else {
                Q=a1[b1[l]]-a2[b1[l]]; Q1=2;
            }
               if(Q<q) {s=l; s1=Q1; q=Q;
            }}
            if(s!=i) {
                    //cout<<"1"<<"    ";
                ans=ans-a1[b1[s]]+a1[i];
                if(s1==2){
                        ans=ans+a2[b1[s]];
                    b2[x2]=b1[s]; x2++;
                    }
                 else   {
                     ans=ans+a3[b1[s]];
                    b3[x3]=b1[s]; x3++;
                    }
                b1[s]=i;
            }
            else {
                if(q1==2){
                        ans=ans+a2[i];
                    b2[x2]=s; x2++;
                    }
                 else   {
                      ans=ans+a3[i];
                    b3[x3]=s; x3++;
                    }
            }
        }
    }
    if(a2[i]==max(a1[i],max(a2[i],a3[i]))){
        if(x2-1<k) {
                ans=ans+a2[i];
                b2[x2]=i;
               x2++;
        }
        else {
//cout<<"2"<<"  ";
            if(a2[i]-a1[i]>a2[i]-a3[i]) {
                q=a2[i]-a3[i]; q1=3;
            }
            else {
                q=a2[i]-a1[i]; q1=1;
            }
            s=i;
            for(l=1;l<x2;l++){
                if(a2[b2[l]]-a1[b2[l]]>a2[b2[l]]-a3[b2[l]]) {
                Q=a2[b2[l]]-a3[b2[l]]; Q1=3;
            }
            else {
                Q=a2[b2[l]]-a1[b2[l]]; Q1=1;
            }
               if(Q<q){ s=l; s1=Q1; q=Q;
            }}
            if(s!=i) {
                  // cout<<"1"<<"   ";
                ans=ans-a2[b2[s]]+a2[i];
                if(s1==1){
                        ans=ans+a1[b2[s]];
                    b1[x1]=b2[s]; x1++;
                    }
                 else   {
                     ans=ans+a3[b2[s]];
                    b3[x3]=b2[s]; x3++;
                    }
                b2[s]=i;
            }
            else {
                if(q1==1){
                        ans=ans+a1[i];
                    b1[x1]=s; x1++;
                    }
                 else   {
                      ans=ans+a3[i];
                    b3[x3]=s; x3++;
                    }
            }
        }
    }
    if(a3[i]==max(a1[i],max(a2[i],a3[i]))){
        if(x3-1<k) {
                ans=ans+a3[i];
                b3[x3]=i;
               x3++;
        }
        else {
           //     cout<<"3";
            if(a3[i]-a2[i]>a3[i]-a1[i]) {
                q=a3[i]-a1[i]; q1=1;
            }
            else {
                q=a3[i]-a2[i]; q1=2;
            }
            s=i;
            for(l=1;l<x3;l++){
                if(a3[b3[l]]-a2[b3[l]]>a3[b3[l]]-a1[b3[l]]) {
                Q=a3[b3[l]]-a1[b3[l]]; Q1=1;
            }
            else {
                Q=a3[b3[l]]-a2[b3[l]]; Q1=2;
            }
               if(Q<q) {s=l; s1=Q1; q=Q;
            }}
            if(s!=i) {
                ans=ans-a3[b3[s]]+a3[i];
                if(s1==2){
                        ans=ans+a2[b3[s]];
                    b2[x2]=b3[s]; x2++;
                    }
                 else   {
                     ans=ans+a1[b3[s]];
                    b1[x1]=b3[s]; x1++;
                    }
                b3[s]=i;
            }
            else {
                if(q1==2){
                        ans=ans+a2[i];
                    b2[x2]=s; x2++;
                    }
                 else   {
                      ans=ans+a1[i];
                    b1[x1]=s; x1++;
                    }
            }
        }
    }
 // cout<<ans<<" ";
}
 cout<<ans<<endl;
//cout<<endl;
}
return 0;
}

