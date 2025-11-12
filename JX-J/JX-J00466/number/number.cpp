#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int p=1;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        char sh=s[i];
        if(sh=='1'||sh=='2'||sh=='3'||sh=='4'||sh=='5'||sh=='6'||sh=='7'||sh=='8'||sh=='9'||sh=='0'){
                sh+='0';
        if(sh=='a'){
            a[p]=1;
            p++;
        }if(sh=='b'){
            a[p]=2;
            p++;
        }if(sh=='c'){
            a[p]=3;
            p++;
        }if(sh=='d'){
            a[p]=4;
            p++;
        }if(sh=='e'){
            a[p]=5;
            p++;
        }if(sh=='f'){
            a[p]=6;
            p++;
        }if(sh=='g'){
            a[p]=7;
            p++;
        }if(sh=='h'){
            a[p]=8;a
            p++;
        }if(sh=='i'){
            a[p]=9;
            p++;
        }if(sh=='`'){
            a[p]=0;
            p++;
        }
        }
    }
    sort(a+1,a+p);
    for(int i=p-1;i>=1;i--)
        cout<<a[i];
    fclose(stdin);
    fclose(stdout);
return 0;
}
