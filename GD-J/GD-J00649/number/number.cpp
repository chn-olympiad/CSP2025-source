#include<bits/stdc++.h>
#include<cstring>
using namespace std;
const int N=1e4+10;
string s;
int num[N],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[++l]=s[i]-'0';
		}
	}
	sort(num+1,num+1+l);
	if(num[l]==0){
		printf("0");
		return 0;
	}
	for(int i=l;i>=1;i--)printf("%d",num[i]);
	return 0;
}
