#include<iostream>
#include<cmath>
using namespace std;
int TFtoTD(string st){//2 10
    int s=0,i;
    for(i=0;i<st.size();i++){
        s += (st[i]-'0')*(st.size()-1-i);
    }
    return s;
}

string TDtoTF(int x){//10 2
    string st;
    while(x>=2){
        st += x%2+'0';
        x /= 2;
    }
    string sts="";
    int i;
    for(i=st.size()-1;i>=0;i--){
        sts += st[i];
    }
    return sts;
}

int NewVoidted(int x1,int x2){
    string st1=TDtoTF(x1),st2=TDtoTF(x2);//  ecosect the pass not
    int i;
    string sts="";
    for(i=0;i<max(st1.size(),st2.size());i++){
        if(st1[i]==0&&st2[i]==0){//  or spaceing (chat
            sts += '0';
            continue;
        }
        sts += '1';
    }
    return TFtoTD(sts);//  in passing doing again
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int t=1,j,d;
    while(t<=n){
        for(i=0;i<=n-t;i++){
            d = a[i];
            for(j=i;j<i+t;j++){
                d = NewVoidted(d,a[j]);
            }
        }
        t++;
    }
    cout<<t;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
