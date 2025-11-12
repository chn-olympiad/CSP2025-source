#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string S;
long long Num[N];
long long ID=0;
bool cmP(int X,int Y){return X>Y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	 
	cin>>S;
	for(int i=0;i<S.length();i++){
		if(S[i]>='0'&&S[i]<='9'){
			if(S[i]=='0')Num[++ID]=0;
			else if(S[i]=='1')Num[++ID]=1;
			else if(S[i]=='2')Num[++ID]=2;
			else if(S[i]=='3')Num[++ID]=3;
			else if(S[i]=='4')Num[++ID]=4;
			else if(S[i]=='5')Num[++ID]=5;
			else if(S[i]=='6')Num[++ID]=6;
			else if(S[i]=='7')Num[++ID]=7;
			else if(S[i]=='8')Num[++ID]=8;
			else if(S[i]=='9')Num[++ID]=9;
		}
	}
	sort(Num+1,Num+ID+1,cmP);
	for(int i=1;i<=ID;i++){
		cout<<Num[i];
	}
	return 0;
}
