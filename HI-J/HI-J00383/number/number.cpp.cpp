#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long num[1000];
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
	int c=0;
	cin>>s;
	
	for(int i=0;i<s.size();i++){
		for(int j=0;j<10;j++){
			if(s[i]==j+'0'){
				
				
				num[c]=j;
				
				c++;
			}
		}	
	}

	sort(num,num+c,cmp);

	for(int i=0;i<c;i++){
		cout<<num[i];
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

