#include<bits/stdc++.h>
using namespace std;
struct corr{
    int a1,a2,a3,idx;
};
bool cmp(corr a,corr b){
    if(a.a1==b.a1){
        if(a.a2==b.a2){
            return a.a3>b.a3;
        }
        return a.a2>b.a2;
    }
    return a.a1>b.a1;
}
bool cmp6(corr a,corr b){
    if(a.a1==b.a1){
        if(a.a2==b.a2){
            return a.a3<b.a3;
        }
        return a.a2<b.a2;
    }
    return a.a1>b.a1;
}
bool cmp4(corr a,corr b){
    if(a.a1==b.a1){
        if(a.a3==b.a3){
            return a.a2>b.a2;
        }
        return a.a3>b.a3;
    }
    return a.a1>b.a1;
}
bool cmp1(corr a,corr b){
    if(a.a2==b.a2){
        if(a.a1==b.a1){
            return a.a3>b.a3;
        }
        return a.a1>b.a1;
    }
    return a.a2>b.a2;
}
bool cmp7(corr a,corr b){
    if(a.a2==b.a2){
        if(a.a1==b.a1){
            return a.a3<b.a3;
        }
        return a.a1<b.a1;
    }
    return a.a2>b.a2;
}
bool cmp3(corr a,corr b){
    if(a.a2==b.a2){
        if(a.a3==b.a3){
            return a.a1>b.a1;
        }
        return a.a3>b.a3;
    }
    return a.a2>b.a2;
}
bool cmp2(corr a,corr b){
    if(a.a3==b.a3){
        if(a.a1==b.a1){
            return a.a2>b.a2;
        }
        return a.a1>b.a1;
    }
    return a.a3>b.a3;
}
bool cmp8(corr a,corr b){
    if(a.a3==b.a3){
        if(a.a1==b.a1){
            return a.a2<b.a2;
        }
        return a.a1<b.a1;
    }
    return a.a3>b.a3;
}
bool cmp5(corr a,corr b){
    if(a.a3==b.a3){
        if(a.a2==b.a2){
            return a.a1>b.a1;
        }
        return a.a2>b.a2;
    }
    return a.a3>b.a3;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        corr arr[n];
        //bool vis[n];

        for(int i=0;i<n;++i){
            cin>>arr[i].a1>>arr[i].a2>>arr[i].a3;
            arr[i].idx=i;
        }
        for(int test=0;test<=8;++test){
            //memset(vis,0,sizeof(vis));
            if(test==0) sort(arr,arr+n,cmp);
            else if(test==1) sort(arr,arr+n,cmp1);
            else if(test==2) sort(arr,arr+n,cmp2);
            else if(test==3) sort(arr,arr+n,cmp4);
            else if(test==4) sort(arr,arr+n,cmp3);
            else if(test==5) sort(arr,arr+n,cmp5);
            else if(test==6) sort(arr,arr+n,cmp6);
            else if(test==7) sort(arr,arr+n,cmp7);
            else if(test==8) sort(arr,arr+n,cmp8);
            int first=0,second=0,third=0,sum=0;
            int c1=0,c2=0,c3=0,s1=0;
            for(int i=0;i<n;++i){
                if((c3>=n/2&&c2>=n/2)||(arr[i].a1>=arr[i].a2&&arr[i].a1>=arr[i].a3&&c1+1<=n/2)){
                    c1++;
                    s1+=arr[i].a1;
                }
                else if(c3>=n/2||(arr[i].a2>=arr[i].a3&&c2+1<=n/2)){
                    c2++;
                    s1+=arr[i].a2;
                }
                else{
                    c3++;
                    s1+=arr[i].a3;
                }
            }
ans=max({ans,sum,s1});
            first=0,second=0,third=0,sum=0;
                for(int i=0;i<n;++i){
                    if(first+1<=n/2){
                        first++;
                        sum+=arr[i].a1;
                    }
                    else if(third+1>n/2||(second+1<=n/2&&arr[i].a2>=arr[i].a3)){
                        second++;
                        sum+=arr[i].a2;
                    }
                    else{
                        third++;
                        sum+=arr[i].a3;
                    }
                }
            ans=max({ans,sum,s1});
            first=0,second=0,third=0,sum=0;
                for(int i=0;i<n;++i){
                    if(second+1<=n/2){
                        second++;
                        sum+=arr[i].a2;
                    }
                    else if(third+1>n/2||(first+1<=n/2&&arr[i].a1>=arr[i].a3)){
                        first++;
                        sum+=arr[i].a1;
                    }
                    else{
                        third++;
                        sum+=arr[i].a3;
                    }
                }
                ans=max({ans,sum,s1});
            first=0,second=0,third=0,sum=0;
                for(int i=0;i<n;++i){
                    if(third+1<=n/2){
                        third++;
                        sum+=arr[i].a3;
                    }
                    else if(second+1>n/2||(first+1<=n/2&&arr[i].a1>=arr[i].a2)){
                        first++;
                        sum+=arr[i].a1;
                    }
                    else{
                        second++;
                        sum+=arr[i].a2;
                    }
                }
            
            ans=max({ans,sum,s1});
        }
        cout<<ans<<'\n';
    }
    return 0;
}
