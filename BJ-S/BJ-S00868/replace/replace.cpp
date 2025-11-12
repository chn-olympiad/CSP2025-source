#include<bits/stdc++.h>
using namespace std;
char s[10005][20005];
char c[10005][20005];
int len[10005];
char a[2000006];
char b[2000006];
char d[2000006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,r;
    cin>>n>>r;
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        scanf("%s",c[i]+1);
        len[i]=strlen(s[i]+1);
    }
    for(int i=1;i<=r;i++){
        int ans=0;
        scanf("%s",a+1);
        scanf("%s",b+1);
        int l=strlen(a+1);
        for(int j=1;j<=l;j++){
                for(int q=1;q<=n;q++){
                    for(int k=1;k<=l;k++){
                        d[k]=a[k];
                    }
                    int flag=1;
                    for(int k=1;k<=len[q];k++){
                        if(d[k+j-1]==s[q][k]){
                            d[k+j-1]=c[q][k];
                        }
                        else{
                            flag=0;
                        }
                    }
                    int flag2=0;
                    if(flag==1){
						flag2=1;
                        for(int k=1;k<=l;k++){
                            if(d[k]!=b[k])flag2=0;
                        }
                    }
                    if(flag2==1){
                        ans++;
                    }
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}
