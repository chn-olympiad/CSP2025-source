#include <iostream>
using namespace std;

int cnt[10];

string S;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	for (int i=0;i<S.length();i++){
		if (S[i]<'0'||S[i]>'9'){
			continue;
		}
		cnt[S[i]-'0']++;
	}
	for (int i=9;i>=0;i--){
		for (int j=cnt[i];j>=1;j--){
			printf("%d",i);
		}
	}
	return 0;
}
 
