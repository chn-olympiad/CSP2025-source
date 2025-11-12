#include<bits/stdc++.h>
using namespace std;
	char a[5000010];
	long long num[100];
	bool boo=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=strlen(a);
	for(long long i=0;i<l;i++){
			if(a[i]<='9' && a[i]>='0'){
				num[a[i]-'0']++;
			}
	}
	for(long long i=9;i>=0;i--){
		if(i==0 && boo==0){
			return 0;
		}
		while(num[i]!=0){
			cout<<i;
			num[i]--;
			boo=1;
		}
	}
	//goodbye.by the way,i can't AK_IOI,i'm sooooo sad.
	return 0;
}
