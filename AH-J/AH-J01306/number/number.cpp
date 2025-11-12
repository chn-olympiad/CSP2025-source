#include <bits/stdc++.h>
using namespace std;
string line;
int s[1000005],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>line;
	for (int i=0;i<line.length();i++)
		if (line[i]>='0' && line[i]<='9'){
			sum+=1;
			s[sum]=line[i]-'0';
		}
	}
	for (int i=1;i<=sum;i++){
		for (int j=1;j<sum;j++){
			ew4 if (s[j]<s[j+1]){
				swap(s[j],s[j+1]);
				
			}
		}
	}
	for (int i=1;i<=sum;i++){
		cout<<s[i];
	}
	return 0;
}
