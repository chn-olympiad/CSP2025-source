#include <bits/stdc++.h>
using namespace std;
int n,a[5010],i,j,k,l,p,m,sumss,maxnum,cnt;
bool vi[5010],t;
struct ab{
    short so[5010];
    int len,dyi;
}solves[50100];
bool cmp(ab aaa,ab aab){
    for(int i=0;i<max(aaa.len,aab.len);i++){
       if(aaa.so[i]!=aab.so[i]) return aaa.so[i]<aab.so[i];
    }
    return 1;
}
void dfs(int pos,int len,int depthh){
    if(depthh==len){
        for(int c=0;c<n;c++){//c++?
            if(vi[c]==1) solves[p].so[solves[p].len++]=c+1;
        }
        p++;
        //cout<<endl;
        return;
    }
    for(int b=0;b<n;b++){
        if(vi[b]==0){
            vi[b]=1;
            dfs(b,len,depthh+1);
            //printf("depth:%d,",depthh);
            //for(int a=0;a<n;a++){
            //    cout<<vi[a]<<' ';
            //}
            //cout<<endl;
            vi[b]=0;
        }
    }
}
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vi[0]=1;
    for(i=3;i<=n;i++){
        for(j=0;j<n;j++){
                //cout<<"\n\n\n\nj="<<j<<"\n\n\n\n";
                //p=0;
                //memset(solves,0,sizeof(solves));
                memset(vi,0,sizeof(vi));
            vi[j]=1;
            dfs(j,i,1);
            vi[j]=0;
            //sort(solves,solves+p,cmp)
        }

    }for(i=0;i<p;i++) for(j=0;j<solves[i].len;j++) cout<<solves[i].so[j]+1<<' ';
            for(k=0;k<p;k++){
                for(m=0;m<p;m++){
                      t=0;
                if(k!=m&&solves[m].dyi==0&&solves[k].dyi==0){
                t=1;
                    for(l=0;l<max(solves[k].len,solves[m].len);l++){
                        if(solves[k].so[l]!=solves[m].so[l]){
                                t=0;
                        }

                        //cout<<0;
                        //if(k==m) break;

                    }
                }
                if(t) solves[m].dyi=1;
                }

            }

            for(i=0;i<p;i++){
                if(solves[i].dyi==0){
                        maxnum=-1;
                        sumss=0;
                    for(j=0;j<solves[i].len;j++){
                        if(maxnum<a[solves[i].so[j]]) maxnum=a[solves[i].so[j]];
                        sumss+=a[solves[i].so[j]];


                    }//for(j=0;j<solves[i].len;j++) cout<<solves[i].so[j]+1<<' ';
                        //cout<<endl<<sumss<<' '<<maxnum<<endl;
                    if(sumss>maxnum*2){
                        cnt++;

                    }
                    cout<<endl;
                }
            }
            cout<<cnt;
    return 0;

}
