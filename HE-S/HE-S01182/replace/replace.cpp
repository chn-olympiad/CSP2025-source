#include<bits/stdc++.h>
using namespace std;

struct ar{
	string str,str1;
};

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	int sum[q];
	memset(sum,0,sizeof(sum));
	ar s[n],s1[q];
	for(int i=0;i<=n-1;i++){
		scanf("%c %c",&s[i].str,&s[i].str1);
	}
	for(int i=0;i<=q-1;q++){
		scanf("%c %c",&s1[i].str,&s1[q].str1);
	}
	for(int i=0;i<=q-1;i++){
		for(int j=0;j<=n-1;j++){
			if(s1[i].str==s[j].str){
				sum[i]++;
				if(s1[i].str1==s[j].str1){
					sum[i]++;
				}
			}
		}
	}
	for(int i=0;i<=q-1;i++){
		printf("%d\n",sum[i]);
	}
	
	return 0;
} 
