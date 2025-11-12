#include<bits/stdc++.h>
using namespace std;
long long n,a[100009],b[100009],c[100009],ans,an,bn,cn,aded[100009],t;
struct pp{
    long long k,num;
    bool w;
    bool operator<(pp d)const {
        return k<d.k;
    }
}pt,tmp;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
            ans=an=bn=cn=0;
            memset(aded,0,sizeof(aded));
        priority_queue<pp> q;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            ans+=a[i];
            b[i]-=a[i];c[i]-=a[i];
            //cout<<b[i]<<' '<<c[i]<<'\n';
            pt.k=b[i];
            pt.w=0;pt.num=i;
            q.push(pt);
            pt.k=c[i];
            pt.w=1;
            q.push(pt);
        }
        an=n;
        while(1){

                if(q.empty()){
                    break;
                }tmp=q.top();q.pop();
//cout<<tmp.k<<'}';
            if(an>n/2){

                if(aded[tmp.num]==0){
                    if(tmp.w==0){
                        if(bn<n/2){
                            ans+=tmp.k;
                            aded[tmp.num]=1;
                            //cout<<'a';
                            bn+=1;
                            an-=1;
                            //cout<<"=";
                        }
                    }else{
                        if(cn<n/2){
                            ans+=tmp.k;
                            aded[tmp.num]=1;
                            //cout<<'b';
                            cn+=1;
                            an-=1;
                            //cout<<"=";
                        }
                    }

                }else{
                    //cout<<"+";
                    continue;
                }
            }else{

                if(tmp.k>0){
                    if(aded[tmp.num]==0){
                    if(tmp.w==0){
                        if(bn<n/2){
                            ans+=tmp.k;
                            aded[tmp.num]=1;
                            //cout<<'a';
                            bn+=1;
                            an-=1;
                            //cout<<"=";
                        }
                    }else{
                        if(cn<n/2){
                            ans+=tmp.k;
                            aded[tmp.num]=1;
                           //cout<<'b';
                            cn+=1;
                            an-=1;
                            //cout<<"=";
                        }
                    }

                }
                }else{
                    break;
                }

            }//cout<<tmp.k<<' '<<tmp.num<<' '<<tmp.w<<'\n';
        }

        cout<<ans<<'\n';
    }

    return 0;
}


