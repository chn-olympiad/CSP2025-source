#include<bits/stdc++.h>
using namespace std;
int a[1000001],i;
int main(){
	char z[1000001];
	freopen("number.in",)
	for(i=1;i<=1000001;i++){
		if(z[i]=='1')
			a[i]=1;
		else if(z[i]=='2')
			a[i]=2;
		else if(z[i]=='3')
			a[i]=3;
		else if(z[i]=='4')
			a[i]=4;
		else if(z[i]=='5')
			a[i]=5;
		else if(z[i]=='6')
			a[i]=6;
		else if(z[i]=='7')
			a[i]=7;
		else if(z[i]=='8')
			a[i]=8;
		else if(z[i]=='9')
			a[i]=9;
		else if(z[i]=='0')
			a[i]=0;
		else if(z[i]=='q'||z[i]=='w'||z[i]=='e'||z[i]=='r'||z[i]=='t'||z[i]=='y'||z=='u'||z=='i'||z=='o'||z=='p'||z=='a'||z=='s'||z=='d'||z=='f'||z=='g'||z=='h'||z=='j'||z=='k'||z=='l'||z=='z'||z=='x'||z=='c'||z=='v'||z=='b'||z=='n'||z=='m'||z=='i')
			i--; 
		else{
			i--;
			break;}}
	sort(a+1,a+i);
	for(int j=1;j<=i;j++)
		cout<<a[j];
}
