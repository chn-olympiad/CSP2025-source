#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N],quq[N];
int qq=0;
void sap(){
	for(int i=0;i<qq;i++)
		for(int j=1;j<qq;j++){
			if(quq[j]<quq[j-1]){
				int x=quq[j];
				quq[j]=quq[j-1];
				quq[j-1]=x;
			}
		}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=99999;i++){
		if(s[i]=='\0'){
			break;
		}else{
			if(s[i]>='0'&&s[i]<='9'){
				quq[qq]=s[i];
				qq++;
			}
		}
	}
	sap();
	for(int i=qq-1;i>=0;i--){
		cout<<quq[i];
	}
	
	return 0;
}

