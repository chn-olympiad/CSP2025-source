#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	int p=0;
	while(cin>>s[p]){
		p++;
	}
    int num[1000005];
    int tail=0;
    for(int i=0;i<p;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[tail]=s[i]-'0';
			tail++;
		}
	}
	sort(num,num+tail);
	for(int i=tail-1;i>=0;i--){
		cout<<num[i];
	}
    return 0;
}
