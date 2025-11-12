#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
ll n,ans,cnt,MA,ls,a[5005],flag[5005];
void f(int x){
    cnt=0;
    if(x==3){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
            cnt=a[k1]+a[k2]+a[k3];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    if(x==4){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    }
    if(x==5){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    }
    }
    if(x==6){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    }
    }
    }
    if(x==7){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    }
    }
    }
    }
     if(x==8){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==9){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            if(MA*2<cnt) ans++;
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==10){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            if(MA*2<cnt) ans++;
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
     if(x==11){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            if(MA*2<cnt) ans++;
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==12){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            if(MA*2<cnt) ans++;
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==13){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==14){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==15){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
        for(int k15=k14+1;k15<=n;k15++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            MA=max(MA,a[k15]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==16){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
        for(int k15=k14+1;k15<=n;k15++){
        for(int k16=k15+1;k16<=n;k16++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15]+a[k16];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            MA=max(MA,a[k15]);
            MA=max(MA,a[k16]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==17){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
        for(int k15=k14+1;k15<=n;k15++){
        for(int k16=k15+1;k16<=n;k16++){
        for(int k17=k16+1;k17<=n;k17++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15]+a[k16]+a[k17];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            MA=max(MA,a[k15]);
            MA=max(MA,a[k16]);
            MA=max(MA,a[k17]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==18){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
        for(int k15=k14+1;k15<=n;k15++){
        for(int k16=k15+1;k16<=n;k16++){
        for(int k17=k16+1;k17<=n;k17++){
        for(int k18=k17+1;k18<=n;k18++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15]+a[k16]+a[k17]+a[k18];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            MA=max(MA,a[k15]);
            MA=max(MA,a[k16]);
            MA=max(MA,a[k17]);
            MA=max(MA,a[k18]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==19){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
        for(int k15=k14+1;k15<=n;k15++){
        for(int k16=k15+1;k16<=n;k16++){
        for(int k17=k16+1;k17<=n;k17++){
        for(int k18=k17+1;k18<=n;k18++){
        for(int k19=k18+1;k19<=n;k19++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15]+a[k16]+a[k17]+a[k18]+a[k19];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            MA=max(MA,a[k15]);
            MA=max(MA,a[k16]);
            MA=max(MA,a[k17]);
            MA=max(MA,a[k18]);
            MA=max(MA,a[k19]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    if(x==20){
        for(int k1=1;k1<=n;k1++){
        for(int k2=k1+1;k2<=n;k2++){
        for(int k3=k2+1;k3<=n;k3++){
        for(int k4=k3+1;k4<=n;k4++){
        for(int k5=k4+1;k5<=n;k5++){
        for(int k6=k5+1;k6<=n;k6++){
        for(int k7=k6+1;k7<=n;k7++){
        for(int k8=k7+1;k8<=n;k8++){
        for(int k9=k8+1;k9<=n;k9++){
        for(int k10=k9+1;k10<=n;k10++){
        for(int k11=k10+1;k11<=n;k11++){
        for(int k12=k11+1;k12<=n;k12++){
        for(int k13=k12+1;k13<=n;k13++){
        for(int k14=k13+1;k14<=n;k14++){
        for(int k15=k14+1;k15<=n;k15++){
        for(int k16=k15+1;k16<=n;k16++){
        for(int k17=k16+1;k17<=n;k17++){
        for(int k18=k17+1;k18<=n;k18++){
        for(int k19=k18+1;k19<=n;k19++){
        for(int k20=k19+1;k20<=n;k20++){
            cnt=a[k1]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]+a[k7]+a[k8]+a[k9]+a[k10]+a[k11]+a[k12]+a[k13]+a[k14]+a[k15]+a[k16]+a[k17]+a[k18]+a[k19]+a[k20];
            MA=0;
            MA=max(a[k1],a[k2]);
            MA=max(MA,a[k3]);
            MA=max(MA,a[k4]);
            MA=max(MA,a[k5]);
            MA=max(MA,a[k6]);
            MA=max(MA,a[k7]);
            MA=max(MA,a[k8]);
            MA=max(MA,a[k9]);
            MA=max(MA,a[k10]);
            MA=max(MA,a[k11]);
            MA=max(MA,a[k12]);
            MA=max(MA,a[k13]);
            MA=max(MA,a[k14]);
            MA=max(MA,a[k15]);
            MA=max(MA,a[k16]);
            MA=max(MA,a[k17]);
            MA=max(MA,a[k18]);
            MA=max(MA,a[k19]);
            MA=max(MA,a[k20]);
            if(MA*2<cnt) ans++;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++){
        f(i);
    }
    cout<<ans%M;
    return 0;
}
