#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
    int a,b,c,t;
}s[100005];
bool cmp1(node n1,node n2){
    return (n1.a-n1.b)>(n2.a-n2.b);
}
bool cmp2(node n1,node n2){
    int a1,a2;
    if(n1.t==1) a1=n1.c-n1.a;
    else a1=n1.c-n1.b;
    if(n2.t==1) a2=n2.c-n2.a;
    else a2=n2.c-n2.b;
    return a1>a2;
}
bool cmp3(node n1,node n2){
    return (n1.a-n1.c)>(n2.a-n2.c);
}
bool cmp4(node n1,node n2){
    int a1,a2;
    if(n1.t==1) a1=n1.b-n1.a;
    else a1=n1.b-n1.c;
    if(n2.t==1) a2=n2.b-n2.a;
    else a2=n2.b-n2.c;
    return a1>a2;
}
bool cmp5(node n1,node n2){
    return (n1.b-n1.c)>(n2.b-n2.c);
}
bool cmp6(node n1,node n2){
    int a1,a2;
    if(n1.t==2) a1=n1.a-n1.b;
    else a1=n1.a-n1.c;
    if(n2.t==2) a2=n2.a-n2.b;
    else a2=n2.a-n2.c;
    return a1>a2;
}
bool cmp12(node n1,node n2){
    return (n1.b-n1.a)>(n2.b-n2.a);
}
bool cmp32(node n1,node n2){
    return (n1.c-n1.a)>(n2.c-n2.a);
}
bool cmp52(node n1,node n2){
    return (n1.c-n1.b)>(n2.c-n2.b);
}
void f(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b>>s[i].c;
    }
    sort(s+1,s+n+1,cmp1);
    int ans=0;
    int ret=0;
    int i;
    for(i=1;i<=n/2;i++){
        if(s[i].a<s[i].b) break;
        ans+=s[i].a;
        s[i].t=1;
    }
    for(;i<=n;i++){
        ans+=s[i].b;
        s[i].t=2;
    }
    sort(s+1,s+n+1,cmp2);
    for(int j=1;j<=n/2;j++){
        int st=0;
        if(s[j].t==1) st=s[j].a;
        else st=s[j].b;
        if(s[j].c<st) break;
        ans-=st;
        ans+=s[j].c;
    }
    ret=max(ret,ans);
    ans=0;
    sort(s+1,s+n+1,cmp3);
        for(i=1;i<=n/2;i++){
        if(s[i].a<s[i].c) break;
        ans+=s[i].a;
        s[i].t=1;
    }
    for(;i<=n;i++){
        ans+=s[i].c;
        s[i].t=3;
    }
    sort(s+1,s+n+1,cmp4);
    for(int j=1;j<=n/2;j++){
        int st=0;
        if(s[j].t==1) st=s[j].a;
        else st=s[j].c;
        if(s[j].b<st) break;
        ans-=st;
        ans+=s[j].b;
    }
    ret=max(ret,ans);
    ans=0;
    sort(s+1,s+n+1,cmp5);
    for(i=1;i<=n/2;i++){
        if(s[i].b<s[i].c) break;
        ans+=s[i].b;
        s[i].t=2;
    }
    for(;i<=n;i++){
        ans+=s[i].c;
        s[i].t=3;
    }
    sort(s+1,s+n+1,cmp6);
    for(int j=1;j<=n/2;j++){
        int st=0;
        if(s[j].t==2) st=s[j].b;
        else st=s[j].c;
        if(s[j].a<st) break;
        ans-=st;
        ans+=s[j].a;
    }ret=max(ret,ans);
    ans=0;
    sort(s+1,s+n+1,cmp12);
    for(i=1;i<=n/2;i++){
        if(s[i].b<s[i].a) break;
        ans+=s[i].b;
        s[i].t=2;
    }
    for(;i<=n;i++){
        ans+=s[i].a;
        s[i].t=1;
    }
    sort(s+1,s+n+1,cmp2);
    for(int j=1;j<=n/2;j++){
        int st=0;
        if(s[j].t==1) st=s[j].a;
        else st=s[j].b;
        if(s[j].c<st) break;
        ans-=st;
        ans+=s[j].c;
    }
    ret=max(ret,ans);
    ans=0;
    sort(s+1,s+n+1,cmp32);
        for(i=1;i<=n/2;i++){
        if(s[i].c<s[i].a) break;
        ans+=s[i].c;
        s[i].t=3;
    }
    for(;i<=n;i++){
        ans+=s[i].a;
        s[i].t=1;
    }
    sort(s+1,s+n+1,cmp4);
    for(int j=1;j<=n/2;j++){
        int st=0;
        if(s[j].t==1) st=s[j].a;
        else st=s[j].c;
        if(s[j].b<st) break;
        ans-=st;
        ans+=s[j].b;
    }
    ret=max(ret,ans);
    ans=0;
    sort(s+1,s+n+1,cmp52);
    for(i=1;i<=n/2;i++){
        if(s[i].c<s[i].b) break;
        ans+=s[i].c;
        s[i].t=3;
    }
    for(;i<=n;i++){
        ans+=s[i].b;
        s[i].t=2;
    }
    sort(s+1,s+n+1,cmp6);
    for(int j=1;j<=n/2;j++){
        int st=0;
        if(s[j].t==2) st=s[j].b;
        else st=s[j].c;
        if(s[j].a<st) break;
        ans-=st;
        ans+=s[j].a;
    }ret=max(ret,ans);
    cout<<ret<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
        f();
	}
	return 0;
}
