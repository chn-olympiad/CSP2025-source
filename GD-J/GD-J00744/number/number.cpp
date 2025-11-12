#include<bits/stdc++.h>
using namespace std;

string s;
char nlist[1000005];
int cnt=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			nlist[cnt]=s[i];
			cnt++;
		}
	}
	
	sort(nlist,nlist+cnt,greater<int>());
	
	for(int i=0;i<cnt;i++){
		cout<<nlist[i];
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}
