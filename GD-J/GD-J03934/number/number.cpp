#include<bits/stdc++.h>
using namespace std;
string a;
const int maxn = 1e6+10;
int numm[maxn];
int t,nn;
char b;
bool inum(char a){
	return (a>='0' && a<='9');
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	t=0;
	cin>>a;
	nn = a.length();
	for(int i = 0; i < nn; i++){
		b=a[i];
		if(b=='\0' || b=='\n')break;
		if(inum(b)){
			numm[t++] = (b-'0');
		}
	}
	sort(numm,numm+t);
	for(int i = t-1; i>=0;i--)cout<<numm[i];
	return 0;
} 
