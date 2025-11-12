#include<bits/stdc++.h>
using namespace std;
string s;
int len,j=0,len2=0,maxx=-1,finish=0,k=0;
int num[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			num[j]=s[i]-'0';
			if(num[j]>maxx) maxx=num[j]-1;
			j++;
			len2++;
		}
	}
	
	while(finish<len2){
		for(k=0;k<len2;k++){
		
			if(num[k]!=-1){
				if(num[k]>maxx){
					cout<<num[k];
					maxx=num[k];
					num[k]=-1;
					finish++;
				
				}
			}
		}
		maxx--;
	}
		return 0;
}
