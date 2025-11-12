#include<bits/stdc++.h>
using namespace std;
int n;
struct f{
    int UUID;
    int tuan1,tuan2,tuan3;
};
string zuigao(f one[],f two[],f three[],int UUID){
    string a1,a2,a3;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(one[j].UUID==UUID)
                a1=j+48;
        }
        for(int j=1;j<=n;j++){
            if(two[j].UUID==UUID)
                a2=j+48;
        }
        for(int j=1;j<=n;j++){
            if(three[j].UUID==UUID)
                a3=j+48;
        }
    }
    return a1+a2+a3;
}
bool pan(short a[]){
    for(int i=1;i<=n;i++)
        if(a[i]==0)
            return 0;
    return 1;
}
bool cmp1(f num1,f num2){
    return num1.tuan1>num2.tuan1;
}
bool cmp2(f num1,f num2){
    return num1.tuan2>num2.tuan2;
}
bool cmp3(f num1,f num2){
    return num1.tuan3>num2.tuan3;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _;
    cin>>_;
    while(1){
        if(_==0)
            return 0;
        cin>>n;
        int l=n/2;
        f a[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i].tuan1>>a[i].tuan2>>a[i].tuan3;
            a[i].UUID=i;
        }/*
        for(int i=1;i<=n;i++){
            cout<<a[i].tuan1<<' '<<a[i].tuan2<<' '<<a[i].tuan3<<" UUID:"<<a[i].UUID<<endl;
        }*/
        f sort1[n+1],sort2[n+1],sort3[n+1];
        for(int i=1;i<=n;i++){
            sort1[i].tuan1=a[i].tuan1;
            sort1[i].tuan2=a[i].tuan2;
            sort1[i].tuan3=a[i].tuan3;
            sort1[i].UUID=a[i].UUID;
        }
        for(int i=1;i<=n;i++){
            sort2[i].tuan1=a[i].tuan1;
            sort2[i].tuan2=a[i].tuan2;
            sort2[i].tuan3=a[i].tuan3;
            sort2[i].UUID=a[i].UUID;
        }
        for(int i=1;i<=n;i++){
            sort3[i].tuan1=a[i].tuan1;
            sort3[i].tuan2=a[i].tuan2;
            sort3[i].tuan3=a[i].tuan3;
            sort3[i].UUID=a[i].UUID;
        }
        sort(sort1+1,sort1+n+1,cmp1);
        sort(sort2+1,sort2+n+1,cmp2);
        sort(sort3+1,sort3+n+1,cmp3);
        /*cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<sort1[i].tuan1<<' '<<sort1[i].tuan2<<' '<<sort1[i].tuan3<<" UUID:"<<sort1[i].UUID<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<sort2[i].tuan1<<' '<<sort2[i].tuan2<<' '<<sort2[i].tuan3<<" UUID:"<<sort2[i].UUID<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<sort3[i].tuan1<<' '<<sort3[i].tuan2<<' '<<sort3[i].tuan3<<" UUID:"<<sort3[i].UUID<<endl;
        }*/
        short fw[n+1]={0};
        short a1[4]={0};

        for(int i=1;i<=n;i++){
            if(fw[i]==0){
                string s=zuigao(sort1,sort2,sort3,i);
                //cout<<s<<endl;
                int x=s[0],y=s[1],z=s[2];
                int mx=0,mz=0;
                if(x>mz&&a1[1]<l){
                    mx=1;
                    mz=x;
                }
                if(y>mz&&a1[2]<l){
                    mx=2;
                    mz=y;
                }
                if(z>mz&&a1[3]<l){
                    mx=3;
                    mz=z;
                }
                fw[i]=mx;
                a1[mx]++;
            }
        }

        int cnt=0;
        for(int i=1;i<=n;i++){
            //cout<<fw[i]<<' ';
            if(fw[i]==1)
                cnt+=a[i].tuan1;
            if(fw[i]==2)
                cnt+=a[i].tuan2;
            if(fw[i]==3)
                cnt+=a[i].tuan3;
        }
        cout<<cnt<<endl;
        _--;
    }
    return 0;
}
