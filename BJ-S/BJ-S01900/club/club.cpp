#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    for(int i=1;i<=a;i++){
        int n,m[10001],s[10001],l[10001],cou=0,k=0,h=0,q=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>m[j]>>s[j]>>l[j];
        }
        for(int j=1;j<=n;j++){
            if(k<=n/2 && m[j]>s[j]){
                if(k<=n/2 && m[j]>l[j]){
                    cou+=m[j];
                    k++;
                }
                else{
                    if(q<=n/2 && m[j]<l[j]){
                        cou+=l[j];
                        q++;
                    }
                    else{
                        cou+=s[j];
                        h++;
                    }
                }
            }
            else{
                if(h<=n/2 && s[j]>l[j]){
                    cou+=s[j];
                    h++;
                }
                else{
                    if(q<=n/2 && m[j]<l[j]){
                        cou+=l[j];
                        q++;
                    }
                    else{
                        cou+=m[j];
                        k++;
                    }
                }
            }
        }
        cout<<cou<<endl;
    }
    return 0;
}
