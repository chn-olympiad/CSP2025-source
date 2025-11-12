#include<bits/stdc++.h>
using namespace std;
string st[5100][1001][2];//st[5100][1000]=下标
long long stl[5100];
//len st[x][0] sort 
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    cin>>a>>b;
    string s[a][2];
    long long sl[a];
    for(int k=0;k<a;k++){
        string s1,s2;
        cin>>s1>>s2;
        long long t=s1.length();
        st[t][stl[t]][0]=s1;
        st[t][stl[t]][1]=s2;
        stl[t]++;
    }
    long long j=0;
    for(int k=0;k<5100;k++){
        for(long long i=0;i<stl[k];i++){
            s[j][0]=st[k][i][0];
            s[j][1]=st[k][i][1];
            sl[j]=k;
            j++;
        }
    }
    for(long long k=0;k<b;k++){
        string s1,s2;
        cin>>s1>>s2;
        long long t=s1.length();
        long long len=t,cnt=0;
        while(t>0){
            for(long long i=0;i<=len-t;i++){
                string st1="",st2="",st3="";
                for(j=0;j<i;j++)st1+=s1[j];
                for(j=i;j<i+t;j++)st2+=s1[j];
                for(j=i+t;j<len;j++)st3+=s1[j];
                for(j=0;j<a;j++){//cout<<st2<<" "<<s[j][0]<<endl;
                    if(st2==s[j][0]){
                        if(st1+s[j][1]+st3==s2)cnt++;
                    }
                }
            }t--;
        }cout<<cnt<<endl;
    }return 0;
}
