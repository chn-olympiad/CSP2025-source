#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
bool b=false;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
        for(int j=a[i];j>=1;j--){
            printf("%d",i);
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
