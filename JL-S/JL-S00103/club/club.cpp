#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000;
int N,M,K;
int matrix[maxn][6];
int lists[3][maxn][2];
int s[5];
int main(){
    int t,n,a,b,c;
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for (int i=0;i<t;i++) {
        //cout<<endl;
        scanf("%d",&n);
        for (int j=0;j<n;j++) {
            scanf("%d %d %d",&a,&b,&c);
            matrix[j][2]=a;
            matrix[j][3]=b;
            matrix[j][4]=c;
            if (max(a,max(b,c))==a) {
                matrix[j][0]=2;     //pos a is max
                if (b>c) matrix[j][1]=3;
                else matrix[j][1]=4;
            }
            else if (max(a,max(b,c))==b) {
                matrix[j][0]=3;     //pos b is max
                if (a>c) matrix[j][1]=2;
                else matrix[j][1]=4;
            }
            else if (max(a,max(b,c))==c) {
                matrix[j][0]=4;     //pos c is max
                if (a>b) matrix[j][1]=2;
                else matrix[j][1]=3;
            }
        }
        for (int j=0;j<n;j++) {     //matrix[j][0]=max_pos
            //cout<<"("<<matrix[j][0]<<")";
            if (s[matrix[j][0]]<n/2) {
                lists[matrix[j][0]-2][s[matrix[j][0]]++][0]=matrix[j][matrix[j][0]];
                lists[matrix[j][0]-2][s[matrix[j][0]]-1][1]=j;
            }
            else {
                int judge=0,delta=0,max_d=0,pos=0;
                for (int k=0;k<s[matrix[j][0]];k++) {
                    //cout<<matrix[j][matrix[j][0]]<<" "<<matrix[lists[matrix[j][0]-2][k][1]][matrix[lists[matrix[j][0]-2][k][1]][1]]<<" "<<lists[matrix[j][0]-2][k][0]<<" "<<matrix[j][matrix[j][1]]<<" ";
                    if (matrix[j][matrix[j][0]]+matrix[lists[matrix[j][0]-2][k][1]][matrix[lists[matrix[j][0]-2][k][1]][1]]>lists[matrix[j][0]-2][k][0]+matrix[j][matrix[j][1]]) {
                        delta=matrix[j][matrix[j][0]]+matrix[lists[matrix[j][0]-2][k][1]][matrix[lists[matrix[j][0]-2][k][1]][1]]-lists[matrix[j][0]-2][k][0]+matrix[j][matrix[j][1]];
                        if (max_d<delta) {
                            max_d=delta;
                            pos=k;
                        }

                        //cout<<"change:"<<k<<" ";

                        judge=1;
                    }
                }
                if (!judge) {
                    lists[matrix[j][1]-2][s[matrix[j][1]]++][0]=matrix[j][matrix[j][1]];
                    lists[matrix[j][1]-2][s[matrix[j][1]]-1][1]=j;
                }
                else {
                    int f=lists[matrix[j][0]-2][pos][1];
                    lists[matrix[j][0]-2][pos][0]=matrix[j][matrix[j][0]];
                    lists[matrix[j][0]-2][pos][1]=j;
                    lists[matrix[f][1]-2][s[matrix[f][1]]++][0]=matrix[f][matrix[f][1]];
                    lists[matrix[f][1]-2][s[matrix[f][1]]-1][1]=f;                     //fu zhi;
                }
            }
        }
        long long ans=0;
        //cout<<"$";
        for (int j=2;j<=4;j++) {
            for (int k=0;k<s[j];k++) {
                //cout<<lists[j-2][k][0]<<" ";
                ans+=lists[j-2][k][0];
            }
            //cout<<endl;
        }
        cout<<ans<<endl;
        s[0]=0;s[1]=0;s[2]=0;s[3]=0;s[4]=0;s[5]=0;
        for (int j=0;j<n+1;j++) {
            for (int k=0;k<6;k++) matrix[j][k]=0;
        }
        for (int j=0;j<3;j++) {
            for (int k=0;k<n+1;k++) {
                lists[j][k][0]=0;
                lists[j][k][1]=0;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
