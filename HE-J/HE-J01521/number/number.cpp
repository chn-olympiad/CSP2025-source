#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s="";
	cin>>s;
	char a[1005]={};
	int b[1005]={};
	int cnt=1;
	int c[100]={};
	for (int i=0;i<=s.length()-1;i++){
		a[i]=(int)s[i];
	}
	for (int i=0;i<=s.length()-1;i++){
			if (a[i]>='0'&&a[i]<='9'){	
				b[cnt]=(int)a[i];
				cnt++;
			}
			
		}
	for (int i=1;i<=cnt-1;i++){
			b[i] = b[i]-48;
	}
	int maxn=0,t=1;
	for (int y=1;y<=cnt-1;y++){
		for (int o=1;o<=s.length()-1;o++){
			if(b[o]>maxn){
				maxn=b[o];
				c[t]=maxn;
				t++;
				b[o]=0;				
			}
		}
		maxn=0;
	}	
	for (int i=t-1;i>=1;i--){
		cout<<c[i];
	}
	return 0;
}
