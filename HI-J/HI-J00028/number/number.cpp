#include<bits/stdc++.h>
using namespace std;
#define ll long long
int g[1000001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string sh;
	string s;
	cin>>s;
	int x=0;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='1'){
			s[x]=s[i];
			x++;
		}
	}
	string shh;
	char maix=s[0],maix2;
	for(int i=0;i<x;i++){
		for(int j=1;j<x;j++){
			if(s[j]>maix){
				maix2=maix;
//				shh=maix;
				maix=s[j];
				s[j]=maix2;
				s[j-1]=maix;
			}
		}
		cout<<s[i];	
		
		
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

