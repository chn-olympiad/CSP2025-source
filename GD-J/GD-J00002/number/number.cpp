#include<bits/stdc++.h>
using namespace std;
string a;
int used[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9' && a[i]>='0'){
			used[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(used[i]){
			printf("%d",i); 
			used[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

