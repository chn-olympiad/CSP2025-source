#include<bits/stdc++.h>
using namespace std;
const int mx=1E6;
string s,s1[mx];
int l=0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a0,sum=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s){
        int i=1;
        if(s>="0"&&s<="9"){
            s1[i]=s;
            i++;
            l++;}}
    for(int i=1;i<=l;i++){
        if(s1[i]=="0"){
            a0++;}
        else if(s1[i]=="1"){
            a1++;}
        else if(s1[i]=="2"){
            a2++;}
        else if(s1[i]=="3"){
            a3++;}
        else if(s1[i]=="4"){
            a4++;}
        else if(s1[i]=="5"){
            a5++;}
        else if(s1[i]=="6"){
            a6++;}
        else if(s1[i]=="7"){
            a7++;}
        else if(s1[i]=="8"){
            a8++;}
        else if(s1[i]=="9"){
            a9++;}}
    while(a9>0){
        sum=sum*10+9;
        a9--;}
    while(a8>0){
        sum=sum*10+8;
        a8--;}
    while(a7>0){
        sum=sum*10+7;
        a7--;}
    while(a6>0){
        sum=sum*10+6;
        a6--;}
    while(a5>0){
        sum=sum*10+5;
        a5--;}
    while(a4>0){
        sum=sum*10+4;
        a4--;}
    while(a3>0){
        sum=sum*10+3;
        a3--;}
    while(a2>0){
        sum=sum*10+2;
        a2--;}
    while(a1>0){
        sum=sum*10+1;
        a1--;}
    while(a0>0){
        sum=sum*10;
        a0--;}
    cout<<sum;
    return 0;
}
