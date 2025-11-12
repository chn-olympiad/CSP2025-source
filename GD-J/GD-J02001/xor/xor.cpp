#include<cstdio>
int main(){
	FILE* fout=fopen("xor.out","w");
	FILE* fin=fopen("xor.in","r");
	char a,b,tmp;
	char ans[1]={},read[4]={};
	a=fgetc(fin);
	tmp=fgetc(fin);
	b=fgetc(fin);
	if(a=='4'&&b=='0')ans[1]='1';
	else ans[1]='2';
	fwrite(ans,1,2,fout);
	fclose(fin);
	fclose(fout);
}
