#include<bits/stdc++.h>
using namespace std;
const int Luogu=1000005;//(something)
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int kkk[Luogu],j=1;
	cin>>s;
	for(int i=0;i<(int)s.length();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){//MVP:||
			kkk[j]=s[i]-'0';
			j++;
		}
	}
	sort(kkk+1,kkk+j+1);//Because I am not good at cmp
	for(int i=j;i>1;i--){//so I choose i--
		cout<<kkk[i];
	}
	return 0;
}
//BY HB-J00277
