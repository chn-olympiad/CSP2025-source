#include<iostream>
#include<cstdio>
int c=0,r=0,n=0,m=0,t=0,t1=0,temp=0;
char ansc[10]{},ansr[10]{},ctmp,rtmp;
int main(){
	FILE* fin=fopen("seat.in","r");
	FILE* fout=fopen("seat.out","w");
	
	n=int(fgetc(fin));
	int tmp=int(fgetc(fin));
	m=int(fgetc(fin));
	tmp=int(fgetc(fin));
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		a[i]=int(fgetc(fin));
		tmp=int(fgetc(fin));
	}
	int a1=a[1];
	a[1]=0;
	for(int i=1;i<=n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<=a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a1<a[i])t++;
		else break;
	}
	while(t1<=t){
		r++;
		for(int i=1;i<=n;i++){
			c++;
			if(c==n){
				c=1;
				break;
			}
		}
	}
	for(int i=0;i<11;i++){
		if(c/10!=0){
			ansc[i]=c%10;
			c/=10; 
		}
		if(r/10!=0){
			ansr[i]=r%10;
			r/=10; 
		}
	}
	for(int i=0;i<11;i++){
		ctmp=ansc[i];
		ansc[i]=ansc[11-i];
		ansc[11-i]=ctmp;
		
		rtmp=ansr[i];
		ansr[i]=ansr[11-i];
		ansr[11-i]=rtmp;
	}
	char none[1]{' '};
	fwrite(ansc,1,10,fout);
	fwrite(none,1,1,fout);
	fwrite(ansr,1,10,fout);
	fclose(fin);
	fclose(fout);
}
