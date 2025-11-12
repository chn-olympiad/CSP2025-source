#include<bits/stdc++.h>
using namespace std;
char s[1000005];
char ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000005);
	for(int j=0,i=0;j<strlen(s);j++)
	    if(s[j]>='0'&&s[j]<='9'){
	    	ans[i]=s[j];
	    	i++;
		}
	for(int i=0;i<strlen(ans);i++)
		for(int j=i+1;j<strlen(ans);j++){
			if(ans[j]>ans[i])
			    swap(ans[i],ans[j]);
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 