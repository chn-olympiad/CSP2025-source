#include<bits/stdc++.h>
using namespace std;
//g++ -O2 -std=c++14 -static c.cpp -o c
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,i,j,k;
    cin>>n>>q;
    string s1[n],s2[n],t1[q],t2[q];
    for(i=0;i<n;i++)
    cin>>s1[i]>>s2[i];
    for(i=0;i<q;i++)
    cin>>t1[i]>>t2[i];
    for(i=0;i<q;i++){
        int num=0;
        int pos1=t1[i].find('b'),pos2=t2[i].find('b');
        for(j=0;j<n;j++){
            int pos3=s1[j].find('b'),pos4=s2[j].find('b');
            if(s1[j]==s2[j])
            continue;
            if(t1[i].length()!=t2[i].length())
            continue;
            if(pos3>pos1||s1[j].length()-pos3>t1[i].length()-pos1)
            continue;
            if(pos4>pos2||s2[j].length()-pos4>t2[i].length()-pos2)
            continue;
            //cout<<pos4<<" "<<s2[j].length()<<" "<<pos2<<" "<<t2[i].length()<<endl;
            if(pos3-pos1!=pos4-pos2)
            continue;
            num++;
        }
        cout<<num<<endl;
    }
}