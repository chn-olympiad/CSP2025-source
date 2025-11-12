#include<bits/stdc++.h>
using namespace std;

int choose[114514];
int cha[114514];

int cp[114514];

void work(){
    int n;
    cin>>n;
    int cnt1=0,cnt2=0,cnt3=0,cnt=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
             if(a>=b&&b>=c)cnt1++,cha[i]=a-b,choose[i]=1,ans+=a;
        else if(a>=c&&c>=b)cnt1++,cha[i]=a-c,choose[i]=1,ans+=a;
        else if(b>=a&&a>=c)cnt2++,cha[i]=b-a,choose[i]=2,ans+=b;
        else if(b>=c&&c>=a)cnt2++,cha[i]=b-c,choose[i]=2,ans+=b;
        else if(c>=a&&a>=b)cnt3++,cha[i]=c-a,choose[i]=3,ans+=c;
        else               cnt3++,cha[i]=c-b,choose[i]=3,ans+=c;
    }
    if(cnt1*2>n){
        for(int i=0;i<n;i++)
            if(choose[i]==1)
                cp[cnt++]=cha[i];
        sort(cp,cp+cnt);
        for(int i=0;i<cnt1-n/2;i++)ans-=cp[i];
    }else if(cnt2*2>n){
        for(int i=0;i<n;i++)
            if(choose[i]==2)
                cp[cnt++]=cha[i];
        sort(cp,cp+cnt);
        for(int i=0;i<cnt2-n/2;i++)ans-=cp[i];
    }else if(cnt3*2>n){
        for(int i=0;i<n;i++)
            if(choose[i]==3)
                cp[cnt++]=cha[i];
        sort(cp,cp+cnt);
        for(int i=0;i<cnt3-n/2;i++)ans-=cp[i];
    }
    cout<<ans<<endl;
    return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    int t;
    cin>>t;
    while(t--)work();
}