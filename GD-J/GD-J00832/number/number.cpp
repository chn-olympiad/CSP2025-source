#include<bits/stdc++.h>
using namespace std;
string a;
int p[1000010],j=0,i=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
  while(a[j]=='a'||a[j]=='b'||a[j]=='c'||a[j]=='d'||a[j]=='e'||a[j]=='f'||a[j]=='g'||a[j]=='h'||a[j]=='i'||a[j]=='j'||a[j]=='k'||a[j]=='m'||a[j]=='n'||a[j]=='l'||a[j]=='o'||a[j]=='p'||a[j]=='q'||a[j]=='r'||a[j]=='s'||a[j]=='t'||a[j]=='u'||a[j]=='v'||a[j]=='w'||a[j]=='x'||a[j]=='y'||a[j]=='z'||a[j]=='0'||a[j]=='1'||a[j]=='2'||a[j]=='3'||a[j]=='4'||a[j]=='5'||a[j]=='6'||a[j]=='7'||a[j]=='8'||a[j]=='9'){
  	if(a[j]=='1'||a[j]=='2'||a[j]=='3'||a[j]=='4'||a[j]=='5'||a[j]=='6'||a[j]=='7'||a[j]=='8'||a[j]=='9'||a[j]=='0'){
			p[i]=int(a[j])-48;
			i++;
		}
		j++;
  }
	j--;
	i--;
	if(j==0)j++;
	sort(p+1,p+1+j);
	for(int ii=j;ii>=(j-i+1);ii--){
		cout<<p[ii];
	}
	cout<<endl;
	return 0;
}
