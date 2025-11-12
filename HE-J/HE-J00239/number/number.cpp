#include <cstdio>
#include <iostream>
using namespace std;
const int S = 1e6 + 10;
char tmp;
int hst,totn;
int numn[10]; //0~9 t
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	while (scanf("%c",&tmp)==1 && tmp!=' ' && tmp!='\n') {
		if (tmp >= '0' && tmp <='9') {	 	
			numn[tmp-'0']++; totn++;
			if (tmp-'0' > hst) hst = tmp-'0';
		}
	}

	for (int i=hst;i>=0;i--) {
		if (numn[i]>0) { 
			hst = i; 
			for (int j=0;j<numn[i];j++) putchar(i+'0');	
		}
	}
	
	return 0;
}

