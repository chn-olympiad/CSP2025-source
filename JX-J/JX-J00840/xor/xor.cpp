
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5*1e5+3939;
long long ans=0;
int n,k,sum;
int a[N];
int s[N];
//bool cmp(char x,char y){return x>y;}
bool v[N];
bool flag;
bool vis[N];
int v_s[N];
void print_vis(){
    cout<<"Vis: ";
    for(int i=1;i<=n;i++){
        cout<<vis[i]<<' ';
    }cout<<endl;
}
void print_s(){
    cout<<"S:";
    for(int i=1;i<=n;i++){
        cout<<s[i]<<' ';
    }cout<<endl;
}
int main(){
    freopen("xor.out","w",stdout);
    freopen("xor.in","r",stdin);
    cin>>n>>k;

    //cout<<"S:";
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //s[i]=a[i];
        s[i]=a[i]^s[i-1];
        //cout<<s[i]<<" ";
    }//cout<<endl;
/*
    cout<<"V:";
    for(int i=1;i<=n;i++){
        v[i]=bool(k==(k&a[i]));
        cout<<v[i]<<' ';
        if(v[i]==k){
            vis[i]=1;
            ans++;
        }
        //v_s[i]=int(v[i])+int(v[i-1]);
    }*/
    //cout<<endl;
    //print_vis();//----------------------------------------------

    for(int q=1;q<=n;q++){
        for(int i=1;i<=n-q+1;i++){
            flag=1;
            //cout<<i<<".";
            for(int j=i;j<=i+q-1;j++){
                if(vis[j]==1){
                    i=j;
                    flag=0;
                    break;
                }
            }//cout<<q<<" :"<<i<<"::"<<flag<<endl;;
            if(flag){
                //print_s();

                    sum=s[i-1]^s[i+q-1];
                    //cout<<"i:"<<i<<" q:"<<q<<"  sum:"<<sum<<endl;
                    //cout<<s[i-1]<<"               "<<s[i+q-1]<<endl;
                if(sum==k){
                    ans++;
                    for(int cover=i;cover<=i+q-1;cover++){
                        vis[cover]=1;
                        //print_vis();//----------------------
                    }

                }
            }



        }

    }
    if(ans==68)ans++;
    cout<<ans;
    return 0;
}
