#include<bits/stdc++.h>
using namespace std;
int a[10000000]={-1};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int lile=0;
	for(int i=0;s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='9'||s[i]=='8'||s[i]=='0'||s[i]=='q'||s[i]=='w'||s[i]=='e'||s[i]=='r'||s[i]=='t'||s[i]=='y'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='p'||s[i]=='a'||s[i]=='s'||s[i]=='d'||s[i]=='f'||s[i]=='f'||s[i]=='g'||s[i]=='h'||s[i]=='j'||s[i]=='k'||s[i]=='l'||s[i]=='z'||s[i]=='x'||s[i]=='c'||s[i]=='v'||s[i]=='b'||s[i]=='n'||s[i]=='m';i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[lile]=s[i]-'0';
			lile++;
		}
	}
	for(int i=0;i<lile-1;i++){
		for(int j=i+1;j<lile;j++){
			if(a[i]<a[j]){
				int lil=a[i];
				a[i]=a[j];
				a[j]=lil;
			}
		}
	}
	for(int i=0;i<lile;i++){
		cout<<a[i];
	}
	return 0;
}
