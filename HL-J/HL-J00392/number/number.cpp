#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000003]={};
	cin>>a;
	int b=0;
	char pp[1000003]={};
	while(1){
		int c=-1;
		int t=-1;
		int p=0;
		for(int i=0;i<strlen(a);i++){
			if(a[i]>='0'&&a[i]<='9'){
				p++;
				if(a[i]-48>c){
					c=a[i]-48;
					t=i;
				}
			}
		}if(t>-1)a[t]='a';
		if(!p)
			break;
		pp[b]=c+48;
		b++;
	}for(int i=0;i<=b;i++){
		cout<<pp[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}