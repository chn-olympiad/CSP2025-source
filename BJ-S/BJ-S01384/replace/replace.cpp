#include <bits/stdc++.h>
using namespace std;

struct node{
    string f,t;
}x[100010];

map<string,string> m;

int main (){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        x[i].f=a,x[i].t=b;
        m[a]=b;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
//        printf("0\n");

        int ans=0;
        for(int i=1;i<=n;i++){
            if(a.find(x[i].f)==b.find(x[i].t)&&a.find(x[i].f)<=a.size()){//如果找到能替换
//                cout<<a.find(x[i].f)<<" "<<x[i].f.size();
                int flag=0;
                for(int j=0;j<a.find(x[i].f);j++){//检查前面
//                    cout<<"j="<<j<<endl;
                    if(a[j]!=b[j]) flag=1;
//                    if(a[j]!=b[j]) cout<<"No at "<<j<<endl;
//                    if(a[j]==b[j]) cout<<j<<" OK!"<<endl;
                }
//                if(flag==0) cout<<"OK front part"<<endl;
                for(int j=a.find(x[i].f)+x[i].f.size();j<a.size();j++){//检查后面
                    if(a[j]!=b[j]) flag=1;
//                    if(a[j]!=b[j]) cout<<"No at "<<j<<endl;
//                    if(a[j]==b[j]) cout<<j<<" OK!"<<endl;
                }
                if(flag==0) ans++;
            }
        }
        printf("%d\n",ans);
        // int ans=0;
        // for(int i=0;i<a.size();i++){//找不同处
        //     if(a[i]!=b[i]){
        //         f+=a[i];
        //         cout<<f<<endl;
        //         if(m[f].size()){//如果可以替换
        //             int flag=0;
        //             for(int j=i-f.size();j<=i;j++){//看替换成不成功
        //                 if(f[i]!=b[i]) flag=1;
        //             }
        //             if(!flag) ans++;//成功
        //         }
        //     }
        // }
        // printf("%d\n",ans);
    }
    return 0;
}//性质A,B一共可拿45分 B 25
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
