#include<bits/stdc++.h>
using namespace std;
int isnum[1000005];
long long xuhao=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long lens=s.size();
	//cout<<s[0];
	for(long long i=0;i<lens;i++){
		if(s[i]=='1'){
			isnum[xuhao]=1;
			xuhao++;
		}
		else if(s[i]=='2'){
			isnum[xuhao]=2;
			xuhao++;
		}
		else if(s[i]=='3'){
			isnum[xuhao]=3;
			xuhao++;
		}
		else if(s[i]=='4'){
			isnum[xuhao]=4;
			xuhao++;
		}
		else if(s[i]=='5'){
			isnum[xuhao]=5;
			xuhao++;
		}
		else if(s[i]=='6'){
			isnum[xuhao]=6;
			xuhao++;
		}
		else if(s[i]=='7'){
			isnum[xuhao]=7;
			xuhao++;
		}
		else if(s[i]=='8'){
			isnum[xuhao]=8;
			xuhao++;
		}
		else if(s[i]=='9'){
			isnum[xuhao]=9;
			xuhao++;
		}
		else if(s[i]=='0'){
			isnum[xuhao]=0;
			xuhao++;
		}
	}
	for(long long i=1;i<xuhao;i++){
		for(long long j=i+1;j<xuhao;j++){
			if(isnum[i]<isnum[j]){
				swap(isnum[i],isnum[j]);
			}
		}
	}
	for(long long i=1;i<xuhao;i++){
		cout<<isnum[i];
	}
	
	return 0;
} 
