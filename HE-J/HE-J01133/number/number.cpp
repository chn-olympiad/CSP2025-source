#include <bits/stdc++.h>
using namespace std;
int s[101];

int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1;i++){
		cin >> s[i];
	}
  for(int k=9;k>0;k--){
  	for(int g=1;g<=1;g++){
  	if(s[g]==k){
  		cout << k;
	  }
	  if(s[g]=='0'){
	  	cout << "0";
	  }
    }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
