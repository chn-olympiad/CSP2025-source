#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node {
    int a,b,c;
}q[10010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int w=n/2;
        int q1=0,q2=0,q3=0,c[10010]={0};
		long long s=0;
        for(int i=0;i<n;i++){
            scanf("%d",q[i].a);
            scanf("%d",q[i].b);
            scanf("%d",q[i].c);
        }
        for(int i=0;i<n;i++){
            int maxx=max(q[i].a,max(q[i].b,q[i].c));
            if(maxx==q[i].a){
                if(maxx==q[i].b){
                    if(maxx==q[i].c){
                        if(q3<w){
                            q3++;
                            s+=q[i].c;
                            continue;
                        }
                    }
                    if(q2<w){
                        q2++;
                        s+=q[i].b;
                        continue;
                    }
                }
                if(q1<w){
                    q1++;
                    s+=q[i].a;
                    continue;
                }
            }
            else if(maxx==q[i].b){
                if(maxx==q[i].c){
                    if(q3<w){
                        q3++;
                        s+=q[i].c;
                        continue;
                    }
                }
                if(q2<w){
                    q2++;
                    s+=q[i].b;
                    continue;
                }
            }
            else {
                if(maxx==q[i].a){
                    if(q1<w){
                        q1++;
                        s+=q[i].a;
                        continue;
                    }
                }
                if(q3<w){
                    q3++;
                    s+=q[i].c;
                    continue;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
