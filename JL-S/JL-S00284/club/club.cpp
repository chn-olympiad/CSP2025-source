#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,t;
    for(int i=0;i<t;i++){
        n=0;
        cin>>n;
        int LIKE[n][4],c[n][4];
        for(int j=0;j<n;j++){
            cin>>LIKE[j][1];
            cin>>LIKE[j][2];
            cin>>LIKE[j][3];
            int lm[n];
            lm[j]=max(LIKE[j][1],(max(LIKE[j][2],LIKE[j][3])));
            //math(cha)
            if(LIKE[j][1]==lm[n]){
                c[j][1]=0;
                c[j][2]=LIKE[j][1]-LIKE[j][2];
                c[j][3]=LIKE[j][1]-LIKE[j][3];
            }
            else if(LIKE[j][2]==lm[n]){
                c[j][2]=0;
                c[j][1]=LIKE[j][2]-LIKE[j][1];
                c[j][1]=LIKE[j][2]-LIKE[j][3];
            }
            else if(LIKE[j][3]==lm[n]){
                c[j][3]=0;
                c[j][2]=LIKE[j][3]-LIKE[j][2];
                c[j][1]=LIKE[j][3]-LIKE[j][3];
            }
            else {
                c[j][3]=0;
                c[j][2]=0;
                c[j][1]=0;
            }
        }
        int member1=0,member2=0,member3=0,s1=0,s2=0,s3=0,note1=0,note2=0,note3=0;
        for(int j=0;j<n;j++){
            if(c[j][1]==0) member1+=lm[j],s1++;
            else if(c[j][2]==0) member2+=lm[j],s2++;
            else if(c[j][3]==0) member3+=lm[j],s3++;
            if(member1>(n/2)){
                int minnow=c[j][2];
                for(int k=0;k<=j;k++){
                    if(c[k][2]<minnow) minnow=c[k][2],note2=k,note3=0;
                    else if(c[k][3]<minnow) minnow=c[k][3],note3=k,note2=0;
                }

                if(note2>0) member2-=c[note2][2];
                else member3-=c[note3][3];
                s1--;
            }
             if(member2>(n/2)){
                int minnow=c[j][1];
                for(int k=0;k<=j;k++){
                    if(c[k][1]<minnow) minnow=c[k][1],note1=k,note3=0;
                    else if(c[k][3]<minnow) minnow=c[k][3],note3=k,note1=0;
                }

                if(note1>0) member1-=c[note1][1];
                else member3-=c[note3][3];
                s2--;
            }
             if(member3>(n/3)){
                int minnow=c[j][1];
                for(int k=0;k<=j;k++){
                    if(c[k][1]<minnow) minnow=c[k][1],note1=k,note2=0;
                    else if(c[k][2]<minnow) minnow=c[k][2],note2=k,note1=0;
                }

                if(note1>0) member1-=c[note1][1];
                else member2-=c[note2][2];
                s3--;
            }
        }
        cout<<member1+member2+member3;
        //cout<<n;
    }

    return 0;
}
