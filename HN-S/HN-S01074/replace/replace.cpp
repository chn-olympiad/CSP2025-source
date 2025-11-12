#include<bits/stdc++.h>
using namespace std;
struct s{
    char s1[1100],s2[1100];
}ss[200050];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,ls1[100050],lt1,lt2,sum=0,ans[100010]={};
    char t1[10050],t2[10050],a1[10050];
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ss[i].s1>>ss[i].s2;
        ls1[i]=strlen(ss[i].s1);
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        strcpy(a1,t1);
        lt1=strlen(t1);
        for(int j=0;j<n;j++){
            sum=0;
            int x=j;
            for(int k=0;x<lt1;x++){
                if(t1[x]==ss[j].s1[k]){
                    sum++;
                    k++;
                }
            }
            if(sum==ls1[j]){
                int y=0,sum1=0;
                for(int k=j;k<=x-1;k++){
                    if(t2[k]==ss[j].s2[y]){
                      a1[k]=ss[j].s2[y];
                      y++;
                    }
                }
                for(int k=0;k<lt1;k++){
                    if(a1[k]==t2[k]){
                        sum1++;
                    }
                }
                if(sum1==lt1&&y==ls1[j]){
                    ans[i]++;
                }
            }
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
