#include<bits/stdc++.h>
using namespace std;
struct b{
    int a;
    int b;
    int c;
};
int m(b a){
    return max(max(a.a,a.b),a.c);
}
int m1(b a){
    if(a.a==m(a))return(max(a.b,a.c));
    if(a.b==m(a))return(max(a.a,a.c));
    if(a.c==m(a))return(max(a.a,a.b));
    return 0;
}
bool c1(b a,b a1){
    //return a.a>=a1.a;
    return m(a)-m1(a)>m(a1)-m1(a1);
}
/*
bool c2(b a,b a1){
    return m(a)-m1(a)>m(a1)-m1(a1);
    return a.b>=a1.b;
}
bool c3(b a,b a1){
    return m(a)-m1(a)>m(a1)-m1(a1);
    return a.c>=a1.c;
}
*/
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
while(T--){
    int n,z=0;
    cin>>n;
    b i1;
    vector<b>a1;
    vector<b>z1,z2,z3;
    for(int i=0;i<n;i++){
        cin>>i1.a>>i1.b>>i1.c;
        if(i1.a>i1.b&&i1.a>i1.c)z1.push_back(i1);
        else
        if(i1.b>i1.a&&i1.b>i1.c)z2.push_back(i1);
        else
        if(i1.c>i1.b&&i1.c>i1.a)z3.push_back(i1);
        else a1.push_back(i1);
    }
    for(auto i:a1)z+=m(i);
    if(z1.size()>n/2){
        sort(z1.begin(),z1.end(),c1);
        for(int i=0;i<z1.size();i++){
            if(i<n/2)z+=z1[i].a;
            else z+=max(z1[i].b,z1[i].c);
        }
        for(auto i:z2)z+=m(i);
        for(auto i:z3)z+=m(i);
    }else if(z2.size()>n/2){
        sort(z2.begin(),z2.end(),c1);
        for(int i=0;i<z2.size();i++){
            if(i<n/2)z+=z2[i].b;
            else z+=max(z2[i].a,z2[i].c);
        }
        for(auto i:z1)z+=m(i);
        for(auto i:z3)z+=m(i);
    }
    else if(z3.size()>n/2){
        sort(z3.begin(),z3.end(),c1);
        for(int i=0;i<z3.size();i++){
            if(i<n/2)z+=z3[i].c;
            else z+=max(z3[i].a,z3[i].b);
        }
        for(auto i:z1)z+=m(i);
        for(auto i:z2)z+=m(i);
    }else{
        for(auto i:z1)z+=m(i);
        for(auto i:z2)z+=m(i);
        for(auto i:z3)z+=m(i);
    }
    cout<<z<<'\n';
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
