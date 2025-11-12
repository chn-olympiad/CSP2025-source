#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
        cout<<a[i];
	}
	return 0;
}
