#include<bits/stdc++.h>
using namespace std;
char s;
long long a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s){
        if(s=='0')
            a[0]++;
        else if(s=='1')
            a[1]++;
        else if(s=='2')
            a[2]++;
        else if(s=='3')
            a[3]++;
        else if(s=='4')
            a[4]++;
        else if(s=='5')
            a[5]++;
        else if(s=='6')
            a[6]++;
        else if(s=='7')
            a[7]++;
        else if(s=='8')
            a[8]++;
        else if(s=='9')
            a[9]++;
    }
    int x=1;
    for(int i=9;i>=0;i++){
        if(i!=0&&a[i]>0)
            x=0;
        for(int j=1;j<=a[i];j++){
            if(i==0&&x==1){
                cout<<0;
                break;
            }
            else{
                cout<<i;
            }
        }
    }
    return 0;
}
