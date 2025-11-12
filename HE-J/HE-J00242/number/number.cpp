#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000]={};
	int a=0;
	while(cin>>s[a]){
		a++;
	}
	int n=0;
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n++;	
		}
	}
	int w[n+5]={};
	int num=0;
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			w[num]=s[i]-48;
			num++;
		}
	}
	for(int i=0;i<num;i++){
		int maxn=-1,tmp;
		for(int j=0;j<=num;j++){
			if(w[j]>maxn){
				maxn=w[j];
				tmp=j;
			}
		}
		cout<<maxn;
		w[tmp]=-1;
	}
	return 0; 
 } 
