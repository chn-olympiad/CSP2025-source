#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m,sql=1;
    FILE *fp=fopen("seat1.in","r+");
    FILE *fw=fopen("seat.out","w+");
    fscanf(fp,"%d%d",&n,&m);
    int s[105]={0};
    for(int i;i<n*m;i++){
        fscanf(fp,"%d",&s[i]);
        if(i>0 && s[i]>s[0]) sql+=1;
    }
    int c=sql%(2*n);
    if(c<=n){
        fprintf(fw,"%d %d\n",(sql+n-1)/n,c);
        fclose(fp);
        fclose(fw);
    }else{
        fprintf(fw,"%d %d\n",(sql+n-1)/n,(n+1)-(c-n));
        fclose(fp);
        fclose(fw);
    }
return 0;}
