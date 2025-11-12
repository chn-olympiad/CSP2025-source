#include<bits/stdc++.h>
using namespace std;
int main(){
    FILE* fi=NULL,*fo=NULL;
    fi=fopen("number.in","rr");
    fo=fopen("number.out","wr");
    char s[1000000];
    memset(s,0,sizeof(s));
    fscanf(fi,"%s",s);
    sort(s,s+1000000,[](const char & a,const char & b)->bool{
         if(a>='0'&&a<='9'){
            if(b>='0'&&b<='9'){
                return a>b;
            }else{
                return 1;
            }
         }else{
            return 0;
         }
    });
    fprintf(fo,"%s",s);
    fclose(fi);
    fclose(fo);
    return 0;
}
