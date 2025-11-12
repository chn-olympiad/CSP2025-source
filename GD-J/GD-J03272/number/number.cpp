#include<bits/stdc++.h>
using namespace std;

char s[200000],s1[200000],s2[200000],anx;
long long lens,lena,a=0,b;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin >> s;
	lens = strlen(s);
	for(int i=0;i<=lens;i++){
		if(s[i]=='0' or s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9'){
			s1[a] = s[i];
			a++;
		}
	}
	lena = strlen(s1);
	for(int i=0;i<=lena;i++){
		anx = '0';
		b=0;
		for(int j=0;j<=lena;j++){
			if(s1[j] == '9' and anx < '9'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				else if(s2[i] == '3'){
					s1[b] = '3';
				}
				else if(s2[i] == '4'){
					s1[b] = '4';
				}
				else if(s2[i] == '5'){
					s1[b] = '5';
				}
				else if(s2[i] == '6'){
					s1[b] = '6';
				}
				else if(s2[i] == '7'){
					s1[b] = '7';
				}
				else if(s2[i] == '8'){
					s1[b] = '8';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '9';
				b=j;
			}
			else if(s1[j] == '8' and s2[i] !='9' and anx < '8'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				else if(s2[i] == '3'){
					s1[b] = '3';
				}
				else if(s2[i] == '4'){
					s1[b] = '4';
				}
				else if(s2[i] == '5'){
					s1[b] = '5';
				}
				else if(s2[i] == '6'){
					s1[b] = '6';
				}
				else if(s2[i] == '7'){
					s1[b] = '7';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '8';
				b=j;
			}
			else if(s1[j] == '7' and s2[i] !='9' and s2[i] != '8' and anx < '7'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				else if(s2[i] == '3'){
					s1[b] = '3';
				}
				else if(s2[i] == '4'){
					s1[b] = '4';
				}
				else if(s2[i] == '5'){
					s1[b] = '5';
				}
				else if(s2[i] == '6'){
					s1[b] = '6';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '7';
				b=j;
			}
			else if(s1[j] == '6' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and anx < '6'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				else if(s2[i] == '3'){
					s1[b] = '3';
				}
				else if(s2[i] == '4'){
					s1[b] = '4';
				}
				else if(s2[i] == '5'){
					s1[b] = '5';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '6';
				b=j;
			}
			else if(s1[j] == '5' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and s2[i] != '6' and anx < '5'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				else if(s2[i] == '3'){
					s1[b] = '3';
				}
				else if(s2[i] == '4'){
					s1[b] = '4';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '5';
				b=j;
			}
			else if(s1[j] == '4' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and s2[i] != '6' and s2[i] != '5' and anx < '4'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				else if(s2[i] == '3'){
					s1[b] = '3';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '4';
				b=j;
			}
			else if(s1[j] == '3' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and s2[i] != '6' and s2[i] != '5' and s2[i] != '4' and anx < '3'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				else if(s2[i] == '2'){
					s1[b] = '2';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '3';
				b=j;
			}
			else if(s1[j] == '2' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and s2[i] != '6' and s2[i] != '5' and s2[i] != '4' and s2[i] != '3' and anx < '2'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				else if(s2[i] == '1'){
					s1[b] = '1';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '2';
				b=j;
			}
			else if(s1[j] == '1' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and s2[i] != '6' and s2[i] != '5' and s2[i] != '4' and s2[i] != '3' and s2[i] != '2' and anx < '1'){
				if(s2[i] == '0'){
					s1[b] = '0';
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				anx = '1';
				b=j;
			}
			else if(s1[j] == '0' and s2[i] !='9' and s2[i] != '8' and s2[i] != '7' and s2[i] != '6' and s2[i] != '5' and s2[i] != '4' and s2[i] != '3' and s2[i] != '2' and s2[i] != '1'){
				if(s2[i] == '0'){
					continue;
				}
				s2[i] = s1[j];
				s1[j] = 'a';
				b=j;
			}
		}
	}
	cout << s2;
	return 0;
}
