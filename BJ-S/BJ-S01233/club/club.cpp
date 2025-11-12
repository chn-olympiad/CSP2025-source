#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;
int t,n,h1[100005],h2[100005],h3[100005],ans[100005],b[100005],t1,c[100005];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    int cnt1=0,cnt2=0,cnt3=0;
    int x1,x2,xx;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>h1[j]>>h2[j]>>h3[j];
            //x1=max(h1[j],h2[j]);
            //x2=max(x1,h3[j]);
            //b[j]=x2;
        }
    }
    sort(h1+1,h1+n+1);
    for(int i=1;i<=t;i++){
        for(int j=n;j>(n/2);j--){
            ans[i]+=h1[j];
        }
    }

    //for(int i=1;i<=n;i++){
    //    for(int j=i;j<=n;j++){
    //        xx=max(b[i],b[j]);
    //        c[i]=xx;
    //    }
    //    if(xx=h1[i]){
    //        h1[100005]=0;
    //    }
    //    else if(xx=h2[i]){
    //        h2[100005]=0;
    //    }
    //    else if(xx=h3[i]){
    //        h3[100005]=0;
    //    }
    //}
    //for(int i=1;i<=t;i++){
    //    for(int j=1;j<=n;j++){
    //       ans[i]+=c[j];
    //    }
    //}
    for(int i=1;i<=t;i++){
        cout<<ans[i]<<endl;
    }
    //for(int i=1;i<=n;i++){
        //for(int j=i;j<=n;j++){
        //    if(h1[i]<h1[j]){//first place-->biggest one
        //        swap(h1[i],h1[j]);
        //        swap(h2[i],h2[j]);
        //        swap(h3[i],h3[j]);//h2,h3 swap at the same time
        //    }
       // }
   // }
   // for(int i=1;i<=n;i++){
      //  if(cnt1<=(n/2)){
      //      ans+=h1[i];
      //      cnt1++;
     //   }
   // }
   // for(int i=1;i<=n;i++){
    //    for(int j=i;j<=n;j++){
        //    if(h2[i]<h2[j]){//first place-->biggest one
       //         swap(h2[i],h2[j]);
      //          swap(h1[i],h1[j]);
     //           swap(h3[i],h3[j]);
       //     }
     //   }
   // }

   //for(int i=1;i<=t;i++){
       // cin>>n;
       // for(int j=1;j<=n;j++){
       //     cin>>h1[j]>>h2[j]>>h3[j];
        //    if(n==2){
        //        if(cnt1<1&&cnt2<1&&cnt3<1){
        //            if(h1[j]>=h2[j]&&h1[j]>=h3[j]){
        //                cnt1++;
        //                ans[i]+=h1[j];
           //             b[i]=h1[j];
           //         }
           //         else if(h2[j]>=h1[j]&&h2[j]>=h3[j]){
           //             cnt2++;
           //             ans[i]+=h2[j];
             //           b[i]=h2[j];
             //       }
             //       else if(h3[j]>=h1[j]&&h3[j]>=h2[j]){
            ////            cnt3++;
               //         ans[i]+=h3[j];
              //          b[i]=h3[j];
              //      }
              //  }
           //     else if(cnt1>=1){
            //        t1=b[i];
             //       b[i]=max(b[i],h1[j]);
             //       if(t1!=b[i]){//b[i]changed
//
               //         ans[i]+=h1[j];
               //     }
                //    else{
             //           ans[i]+=b[i];
                 //   }
                  //  t1=0;
               // }
               // else if(cnt2>=1){
               // //    t1=b[i];
               //     b[i]=max(b[i],h2[j]);
               //     if(t1!=b[i]){
              //          ans[i]+=h2[j];
            //        }
              //      else{
               //         ans[i]+=b[i];
               //     }
               //     t1=0;
               // }
               // else if(cnt3>=1){
               //     t1=b[i];
                //    b[i]=max(b[i],h3[j]);
                 //   if(t1!=b[i]){
              //          ans[i]+=h3[j];
              //      }
               //     else{
             //           ans[i]+=b[i];
          //          }
          //          t1=0;
           //     }
           // }
           // else{
                //if(h1[j]>h2[j]&&h1[j]>h3[j]){
               //     if(cnt1<=n/2){
                //        ans[i]+=h1[j];
                //        cnt1++;
                 //   }
                 //   else{
                  //      if(h2[j]>h3[j]){
                  //          if(cnt2<=n/2){
                   //             ans[i]+=h2[j];
                   //             cnt2++;
                    //        }
                    //        else{
                     //          ans[i]+=h3[j];
                   //             cnt3++;
                     //       }
                   //     }
                 //   }
               // }
               // else if(h2[j]>h1[j]&&h2[j]>h3[j]){
               //     if(cnt2<=n/2){
                //        ans[i]+=h2[j];
                //        cnt2++;
                 //   }
                   // else{
                   //     if(h1[j]>h3[j]){
                    //        if(cnt1<=n/2){
                    //            ans[i]+=h1[j];
                     //           cnt1++;
                //            }
                 //           else{
                //                ans[i]+=h3[j];
                 //               cnt3++;
               //             }
               //         }
              //      }
              //  }
              //  else if(h3[j]>h1[j]&&h3[j]>h2[j]){
              //      if(cnt3<=n/2){
               //         ans[i]+=h3[j];
                  //      cnt3++;
               //     }
               //     else{
               //        if(h1[j]>h2[j]){
                 //           if(cnt1<=n/2){
                   //            ans[i]+=h1[j];
                   //             cnt1++;
                    //        }
                     //       else{
                     //           ans[i]+=h2[j];
                     //           cnt2++;
                    //        }
                   //     }
                  //  }
               // }
           // }

        //}
   // }
   //for(int i=1;i<=t;i++){
        //cout<<ans[i]<<endl;
   // }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
