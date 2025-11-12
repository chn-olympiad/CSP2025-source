#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        int sum=a+b+c;
        if(sum>max(a,max(b,c))*2)cout<<1;
        else cout<<0;
        return 0;
    }
    else if(n==4){
        int a,b,c,d,num=0;
        cin>>a>>b>>c>>d;
        int q=a+b+c,w=a+c+d,e=b+c+d,r=a+b+c+d,t=a+b+d;
        if(q>max(a,max(b,c))*2) num++;
        if(w>max(a,max(d,c))*2) num++;
        if(e>max(d,max(b,c))*2) num++;
        if(t>max(a,max(b,d))*2) num++;
        if(r>max(a,max(b,max(c,d)))*2) num++;
        cout<<num;
        return 0;
    }
    else if(n==5){
        int a,b,c,d,f,num=0;
        cin>>a>>b>>c>>d>>f;
        int r=a+b+c+d,q=a+b+c,w=a+b+d,e=a+b+f,v=a+c+d,t=a+c+f,y=a+f+d,u=b+c+d,j=b+c+f,h=b+d+f,g=c+d+f,i=b+c+d+f,o=a+b+c+d+f,p=a+c+d+f,l=a+b+d+f,k=a+b+c+f;
        if(q>max(a,max(b,c))*2) num++;
        if(w>max(a,max(b,d))*2) num++;
        if(e>max(a,max(b,f))*2) num++;
        if(v>max(a,max(c,d))*2) num++;
        if(t>max(a,max(c,f))*2) num++;
        if(y>max(a,max(d,f))*2) num++;
        if(u>max(b,max(c,d))*2) num++;
        if(j>max(b,max(f,c))*2) num++;
        if(h>max(b,max(d,f))*2) num++;
        if(g>max(c,max(d,f))*2) num++;
        if(r>max(a,max(b,max(c,d)))*2) num++;
        if(i>max(f,max(b,max(c,d)))*2) num++;
        if(p>max(a,max(f,max(c,d)))*2) num++;
        if(l>max(a,max(b,max(f,d)))*2) num++;
        if(k>max(a,max(b,max(c,f)))*2) num++;
        if(o>max(a,max(b,max(c,max(d,f))))*2) num++;
        cout<<num;
        return 0;
    }
    cout<<n;
    return 0;
}
