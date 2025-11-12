#include<string>
#include<cstdio>
#include<cmath>
int main(){
	FILE* fin=fopen("seat.in","r");
	FILE* fout=fopen("seat.out","w");
	char a,b,tmp;
	char ans[1]={};
	tmp=fgetc(fin);
	tmp=fgetc(fin);
	b=fgetc(fin);
	if(b=='1')ans[1]='9';
	else ans[1]='6';
	fwrite(ans,1,2,fout);
	fclose(fin);
	fclose(fout);
}
