#include<bits/stdc++.h>
using namespace std;
char s[200100][2][25000100],t[200100][2][5000100];
int n,q;
int strlen(int top){
	int k=0;
	while(k++){
		if((t[top][1][k]==' '&&t[top][2][k]==' ')) break;
		if((t[top][1][k]==' '&&t[top][2][k]!=' ')||(t[top][2][k]==' '&&t[top][1][k]!=' ')) return 0;
	}
	return 1;
}
int change(int o,int top){
	while(o++){
		if(t[top][1][o]!=s[top][2][o]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	int top=1;
	while(top<=q){
		if(strlen(top)){
			cout<<0;
		}else{
			int o=0,sum;
			while(t[top][1][o++]==s[top][1][o]){
				if(change(o,top)){
					while(o++){
						if(s[top][2][o]==' ') break;
						else t[top][1][o]=s[top][2][o];
					}
					if(t[top][1]==t[top][2]){
						sum++;
					}
					while(--o){
						t[top][1][o]=s[top][1][o];
					}
				}
			}
			top++;
		}
		cout<<endl;
	}
	return 0;
}
