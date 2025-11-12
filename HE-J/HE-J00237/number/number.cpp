#include<iostream>
#include<cstring>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int b=0,c[100000],d;
char a[100000];
fgets(a,100000,stdin);
for(int i=0;i<strlen(a);i++){
	if(a[i]=='0'){
		c[b]=0;
		b++;
	}
		if(a[i]=='1'){
		c[b]=1;
		b++;
	}

		if(a[i]=='2'){
		c[b]=2;
		b++;
	}

		if(a[i]=='3'){
		c[b]=3;
		b++;
	}

		if(a[i]=='4'){
		c[b]=4;
		b++;
	}

		if(a[i]=='5'){
		c[b]=5;
		b++;

	}
		if(a[i]=='6'){
		c[b]=6;
		b++;
	}
		if(a[i]=='7'){
		c[b]=7;
		b++;

	}
		if(a[i]=='8'){
		c[b]=8;
		b++;

	}
		if(a[i]=='9'){
		c[b]=9;
		b++;

	}
}
for(int f=0;f<strlen(a);f++){
    for(int n=0;n<strlen(a)-1;n++){
        if(c[n]<c[n+1]){
            d=c[n+1];
            c[n+1]=c[n];
            c[n]=d;
        }
    }
}
for(int h;h<b;h++){
 cout<<c[h];
}
fclose(stdin);
fclose(stdout);
return 0;
}


