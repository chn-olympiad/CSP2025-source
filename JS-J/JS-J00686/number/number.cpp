#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    //freopen("number.in","r","stdin");
    //freopen("number.out","r","stdout");
    int a[10],j,l,i;
    string s;
    cin>>s;
    j=1;
    l=s.length();
    for(i=1;i<=l;i++)
    if(s=='0'){
        a[0]=a[0]+1;
        j++;
    }
    else if(s=='1'){
        a[1]=a[1]+1;
        j++;
    }
    else if(s=='2'){
        a[2]=a[2]+1;
        j++;
    }
    else if(s=='3'){
        a[3]=a[3]+1;
        j++;
    }
    else if(s=='4'){
        a[4]=a[4]+1;
        j++;
    }
    else if(s=='5'){
        a[5]=a[5]+1;
        j++;
    }
    else if(s=='6'){
        a[6]=a[6]+1;
        j++;
    }
    else if(s=='7'){
        a[7]=a[7]+1;
        j++;
    }
    else if(s=='8'){
        a[8]=a[8]+1;
        j++;
    }
    else if(s=='9'){
        a[9]=a[9]+1;
        j++;
    }
    for(i=1;i<=a[9];i++)
        cout<<9;
    for(i=1;i<=a[8];i++)
        cout<<8;
    for(i=1;i<=a[7];i++)
        cout<<7;
    for(i=1;i<=a[6];i++)
        cout<<6;
    for(i=1;i<=a[5];i++)
        cout<<5;
    for(i=1;i<=a[4];i++)
        cout<<4;
    for(i=1;i<=a[3];i++)
        cout<<3;
    for(i=1;i<=a[2];i++)
        cout<<2;
    for(i=1;i<=a[1];i++)
        cout<<1;
    for(i=1;i<=a[0];i++)
        cout<<0;
    return 0;
}
