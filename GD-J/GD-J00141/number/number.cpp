#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[100005];
	int k,big = -1;
	string word;
	cin>>word;
	k = word.length();
	for(int i = 0;i < k;i++){
		if(word[i] > big){
			big = word[i];
		}
	}
	cout<<big;

	return 0;

}
