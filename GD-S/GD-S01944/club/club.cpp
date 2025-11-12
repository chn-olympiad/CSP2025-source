#include<iostream>
#include<algorithm>
using namespace std;
int l[300000];
int o[3];
int tl[3][100000];
int n,p,ans;
int main(){
    freopen("club5.in","r",stdin);
    freopen("club5.out","w",stdout);
    int t;cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        o[0]=0,o[1]=0,o[2]=0;
        for(int i=0;i<n;i++){
            p=-1;
            for(int j=0;j<3;j++){
                scanf("%d",&l[i*3+j]);
                if(l[i*3+j]>(p==-1?-1:l[i*3+p]))p=j;
            }
            ans+=l[i*3+p];
            if(p==0)tl[p][o[p]++]=l[i*3+p]-max(l[i*3+1],l[i*3+2]);
            if(p==1)tl[p][o[p]++]=l[i*3+p]-max(l[i*3],l[i*3+2]);
            if(p==2)tl[p][o[p]++]=l[i*3+p]-max(l[i*3],l[i*3+1]);
        }
        int j=0;
        for(;j<3;j++)if(o[j]>n/2)break;
        int le=0;
        sort(tl[j],tl[j]+o[j]);
        for(int i=0;i<o[j]-n/2;i++)ans-=tl[j][i];
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}