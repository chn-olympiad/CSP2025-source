#include <bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int numcnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			num[numcnt]=int(s[i]-48);
			numcnt++;	
		}
	}
	sort(num,num+numcnt,greater<int>());
	for(int i=0;i<numcnt;i++){
		printf("%d",num[i]);
	}
	return 0;
}

