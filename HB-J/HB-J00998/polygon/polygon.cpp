#include<bits/stdc++.h>
using namespace std;
const int mx=1E7;
int n,m[mx],x,sum=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    sort(m+1,m+n+1);
    x=m[n];
    if(n<3){
        sum=0;
    }
    if(n>=3){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    if(m[a]+m[b]+m[c]>x*2){
                        sum++;}}}}}
    if(n>=4){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        if(m[a]+m[b]+m[c]+m[d]>x*2){
                            sum++;}}}}}}
    if(n>=5){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            if(m[a]+m[b]+m[c]+m[d]+m[e]>x*2){
                                sum++;}}}}}}}
    if(n>=6){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                if(m[a]+m[b]+m[c]+m[d]+m[e]+m[f]>x*2){
                                    sum++;}}}}}}}}
    if(n>=7){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    if(m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g]>x*2){
                                        sum++;}}}}}}}}}
    if(n>=8){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        if(m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g]+m[h]>x*2){
                                            sum++;}}}}}}}}}}
   if(n>=9){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            if(m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g]+m[h]+m[i]>x*2){
                                                sum++;}}}}}}}}}}}
     if(n>=10){
        for(int a=1;a<=n;a++){
            for(int b=a+1;b<=n;b++){
                for(int c=b+1;c<=n;c++){
                    for(int d=c+1;d<=n;d++){
                        for(int e=d+1;e<=n;e++){
                            for(int f=e+1;f<=n;f++){
                                for(int g=f+1;g<=n;g++){
                                    for(int h=g+1;h<=n;h++){
                                        for(int i=h+1;i<=n;i++){
                                            for(int j=i+1;j<=n;j++){
                                                if(m[a]+m[b]+m[c]+m[d]+m[e]+m[f]+m[g]+m[h]+m[i]+m[j]>x*2){
                                                    sum++;}}}}}}}}}}}}
    cout<<sum%998244353;
    return 0;
}
