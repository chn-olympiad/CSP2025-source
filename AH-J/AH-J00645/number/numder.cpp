#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a="0";
    cin>>a;
    int szgs=0;
    long long cd=a.length();
    if(cd==1)cout<<a;
    else{
        char b[cd]={'a'};
        for(int i=0;i<=cd-1;i++){
            if(a[i]>='0'&&a[i]<='9'){
                    szgs++;
                    b[i]=a[i];
                }
        }
        int jh;
        for(int i1=0;i1<=szgs-1;i1++){
            for(int i3=0;i3<=szgs-1;i3++){
                if(b[i3]<b[i3+1]){
                    jh=b[i3+1];
                    b[i3+1]=b[i3];
                    b[i3]=jh;
                    }
                }
            }
        int i2=0;
        while(b[i2]!='a'){
            cout<<b[i2];
            i2++;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
