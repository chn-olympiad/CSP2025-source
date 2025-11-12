#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n=a.size();
    int num0=0,num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0;
    for(int i=0;i<n;i++){
        if(a[i]=='0')num0++;
        if(a[i]=='1')num1++;
        if(a[i]=='2')num2++;
        if(a[i]=='3')num3++;
        if(a[i]=='4')num4++;
        if(a[i]=='5')num5++;
        if(a[i]=='6')num6++;
        if(a[i]=='7')num7++;
        if(a[i]=='8')num8++;
        if(a[i]=='9')num9++;

    }
    for(int i=1;i<=num9;i++){
        cout<<9;
    }
    for(int i=1;i<=num8;i++){
        cout<<8;
    }
    for(int i=1;i<=num7;i++){
        cout<<7;
    }
    for(int i=1;i<=num6;i++){
        cout<<6;
    }
    for(int i=1;i<=num5;i++){
        cout<<5;
    }
    for(int i=1;i<=num4;i++){
        cout<<4;
    }
    for(int i=1;i<=num3;i++){
        cout<<3;
    }
    for(int i=1;i<=num2;i++){
        cout<<2;
    }
    for(int i=1;i<=num1;i++){
        cout<<1;
    }
    for(int i=1;i<=num0;i++){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

