#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int numm[N];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	int countt=0;
	cin>>s;
	
	int lengg=s.length();
	for(int i=0;i<lengg;i++){
		if((int)s[i]>=48 && (int)s[i]<=57){
			numm[countt]=s[i];
			countt++;
		}
	}
	
	int lernn=countt;
	sort(numm,numm+lernn);
	
	for(int i=countt-1;i>=0;i--){
		cout<<(char)numm[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
