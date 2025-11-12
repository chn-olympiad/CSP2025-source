#include<bits/stdc++.h>
using namespace std;
const int N = 200010;

int n,q;
string s1[N],s2[N];
string q1[N],q2[N];
string select1,select2,select1b,select2b,select1a,select2a;

int find1(string target, int n){
    for(int i = 1; i <= n; i++)
        if(s1[i] == target) return i;
    return -1;
}
int find2(string target, int n){
    for(int i = 1; i <= n; i++)
        if(s2[i] == target) return i;
    return -2;
}



int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);


    scanf("%d%d",&n,&q);
    getchar();

    string a;
    for(int i = 1; i <= n; i++){
        while(true){
            a = getchar();
            if(a != " " && a != "\n") s1[i] = s1[i]+a;
            else break;
        }
        while(true){
            a = getchar();
            if(a != " " && a != "\n") s2[i] = s2[i]+a;
            else break;
        }

    }

    while(q--){
        int ans = 0;
        int ii = 1;
        while(true){
            a = getchar();
            if(a != " " && a != "\n") q1[ii++] = a;
            else break;
        }
        int jj = 1;
        while(true){
            a = getchar();
            if(a != " " && a != "\n") q2[jj++] = a;
            else break;
        }

        if(ii != jj){
            ans = 0;
        }
        else{
            int length = --ii;
            for(int i = 0; i < length; i++){

                for(int j = i+1; j <= length; j++){

                    select1 = "",select2 = "",select1a = "",select1b = "",select2a = "",select2b = "";

                    for(int k = 1;k <= i; k++){
                        select1b = select1b+q1[k];
                        select2b = select2b+q2[k];

                    }
                    for(int k = i+1;k <= j; k++){
                        select1 = select1+q1[k];
                        select2 = select2+q2[k];
                    }

                    for(int k = j+1;k <= length; k++){
                        select1a = select1a+q1[k];
                        select2a = select2a+q2[k];
                    }

                    if(find1(select1,n) == find2(select2,n) && select1b == select2b && select1a == select2a) ans++;

                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;

}





