#include<cstdio>
int max(int a,int b){
	if(a>b)return a;
	return b;
}
char ch,g,num[1000000]={},str[1000000]={},ans[1000000]={};
int ti=0,c=0,m=0,top=10,tmp;
int main(){
FILE* fin=fopen("number.in","r");FILE* fout=fopen("number.out","w");
while(EOF){g=fgetc(fin);tmp=fgetc(fin);str[ti]=g;ti++;} 
for(;c<ti;c++){ch=char(str[c]);
switch(ch){case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':num[c]=ch;break;}}
for(int i=0;i<c;i++){if(m<=top)m=max(int(num[i]),int(num[i+1]));top=m;ans[i]=m;}
fwrite(ans,1,1000000,fout);
fclose(fin);
fclose(fout);
}
